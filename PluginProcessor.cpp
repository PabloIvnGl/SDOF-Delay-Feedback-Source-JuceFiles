/*
  ==============================================================================

    SDOF DELAY FEEDBACK STEREO 
                                                Por: Pablo Ivan Gutierrez Legent
                                                                fecha: 2024-2025               
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SDOFDelayFeedbackAudioProcessor::SDOFDelayFeedbackAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
    parameters(*this, nullptr, juce::Identifier("Parameters_state"),
        {
          std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "TimeDelayL", 1 },
                                                      "TDL",
                                                      0.0f,
                                                      1.9f,
                                                      0.0f),

          std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "TimeDelayR", 1 },
                                                      "TDR",
                                                      0.0f,
                                                      1.9f,
                                                      0.0f),


          std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "DryGL", 1 },
                                                      "DryGL",
                                                      0.0f,
                                                      0.9f,
                                                      0.9f),


          std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "WetGL", 1 },
                                                      "WetGL",
                                                      0.0f,
                                                      0.9f,
                                                      0.0f),

          std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "DryGR", 1 },
                                                      "DryGR",
                                                      0.0f,
                                                      0.9f,
                                                      0.9f),

          std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "WetGR", 1 },
                                                      "WetGR",
                                                      0.0f,
                                                      0.9f,
                                                      0.0f),

          std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "FeedBackGL", 1 },
                                                      "FeedBackGL",
                                                      0.0f,
                                                      0.9f,
                                                      0.0f),

          std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "FeedBackGR", 1 },
                                                      "FeedBackGR",
                                                      0.0f,
                                                      0.9f,
                                                      0.0f),
        })
{
    CurrentTimeDelayL = parameters.getRawParameterValue("TimeDelayL");
    CurrentTimeDelayR = parameters.getRawParameterValue("TimeDelayR");
    CurrentDryGL = parameters.getRawParameterValue("DryGL");
    CurrentWetGL = parameters.getRawParameterValue("WetGL");
    CurrentDryGR = parameters.getRawParameterValue("DryGR");
    CurrentWetGR = parameters.getRawParameterValue("WetGR");
    CurrentFeedBackGL = parameters.getRawParameterValue("FeedBackGL");
    CurrentFeedBackGR = parameters.getRawParameterValue("FeedBackGR");
}

SDOFDelayFeedbackAudioProcessor::~SDOFDelayFeedbackAudioProcessor()
{
}

//==============================================================================
const juce::String SDOFDelayFeedbackAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SDOFDelayFeedbackAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SDOFDelayFeedbackAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SDOFDelayFeedbackAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SDOFDelayFeedbackAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SDOFDelayFeedbackAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SDOFDelayFeedbackAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SDOFDelayFeedbackAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SDOFDelayFeedbackAudioProcessor::getProgramName (int index)
{
    return {};
}

void SDOFDelayFeedbackAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SDOFDelayFeedbackAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    PreviousTimeDelayL = *CurrentTimeDelayL;
    PreviousTimeDelayR = *CurrentTimeDelayR;
    PreviousDryGL = *CurrentDryGL;
    PreviousWetGR = *CurrentWetGR;
    PreviousDryGR = *CurrentDryGR;
    PreviousWetGL = *CurrentWetGL;
    PreviousFeedBackGL = *CurrentFeedBackGL;
    PreviousFeedBackGR = *CurrentFeedBackGR;


    //BufferDelayL = new FeedbackDelay(getSampleRate());
    //BufferDelayR = new FeedbackDelay(getSampleRate());

    vector_1 = new WindowVector(samplesPerBlock);
    vector_1->SetRamp(PreviousDryGL, *CurrentDryGL);

    vector_2 = new WindowVector(samplesPerBlock);
    vector_2->SetRamp(PreviousWetGL, *CurrentWetGL);

    vector_3 = new WindowVector(samplesPerBlock);
    vector_3->SetRamp(PreviousDryGR, *CurrentDryGR);

    vector_4 = new WindowVector(samplesPerBlock);
    vector_4->SetRamp(PreviousWetGR, *CurrentWetGR);

    vector_5 = new WindowVector(samplesPerBlock);
    vector_5->SetRamp(PreviousFeedBackGL, *CurrentFeedBackGL);

    vector_6 = new WindowVector(samplesPerBlock);
    vector_6->SetRamp(PreviousFeedBackGR, *CurrentFeedBackGR);

    vector_7 = new WindowVector(samplesPerBlock);
    vector_7->SetRamp(PreviousTimeDelayL, *CurrentTimeDelayL);

    vector_8 = new WindowVector(samplesPerBlock);
    vector_8->SetRamp(PreviousTimeDelayR, *CurrentTimeDelayR);


    // Valores COMPRESION 

}

void SDOFDelayFeedbackAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SDOFDelayFeedbackAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SDOFDelayFeedbackAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();



    vector_1->SetRamp(PreviousDryGL, *CurrentDryGL);
    PreviousDryGL = *CurrentDryGL;

    vector_2->SetRamp(PreviousWetGL, *CurrentWetGL);
    PreviousWetGL = *CurrentWetGL;

    vector_3->SetRamp(PreviousDryGR, *CurrentDryGR);
    PreviousDryGR = *CurrentDryGR;

    vector_4->SetRamp(PreviousWetGR, *CurrentWetGR);
    PreviousWetGR = *CurrentWetGR;

    vector_5->SetRamp(PreviousFeedBackGL, *CurrentFeedBackGL);
    PreviousFeedBackGL = *CurrentFeedBackGL;

    vector_6->SetRamp(PreviousFeedBackGR, *CurrentFeedBackGR);
    PreviousFeedBackGR = *CurrentFeedBackGR;

    vector_7->SetRamp(PreviousTimeDelayL, *CurrentTimeDelayL);
    PreviousTimeDelayL = *CurrentTimeDelayL;

    vector_8->SetRamp(PreviousTimeDelayR, *CurrentTimeDelayR);
    PreviousTimeDelayR = *CurrentTimeDelayR;


    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());
    {

        //auto TimeDelayLSamples = (std::min(std::max(roundf(getSampleRate() * *CurrentTimeDelayL), 1.0f), 82199.0f));//static_cast<float>(maxtimesamplesL)));
       // auto TimeDelayRSamples = (std::min(std::max(roundf(getSampleRate() * *CurrentTimeDelayR), 1.0f), 82199.0f));


        auto outputCircularBufferL = 0.0f;
        auto outputCircularBufferR = 0.0f;

        auto auxtdl = (getSampleRate() * *CurrentTimeDelayL);
        auto auxtdr = (getSampleRate() * *CurrentTimeDelayR);

        auto TimeDelayLSamples = auxtdl;
        auto TimeDelayRSamples = auxtdr;
        auto DryGL_Fx = CurrentDryGL->load();
        auto DryGR_Fx = CurrentDryGR->load();
        auto WetGL_Fx = CurrentWetGL->load();
        auto WetGR_Fx = CurrentWetGR->load();
        auto FeedBackL_Fx = CurrentFeedBackGL->load();
        auto FeedBackR_Fx = CurrentFeedBackGR->load();


        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {

            for (int i = 0; i < buffer.getNumSamples(); i++)
            {

                //Sample del buffer que entra al circular buffer (señal limpia)

                //auto sample = buffer.getReadPointer(channel)[i];
                auto sampleL = buffer.getReadPointer(0)[i];
                auto sampleR = buffer.getReadPointer(1)[i];

                //Compresion a la señal de entrada

                 /*%% Compresión            (DE CODIGO DE MATLAB)
                     umbral = 0.35;% amplitud entre 0 y 1
                     entrada = 4;
                 salida = 1;
                 razon = entrada / salida;% ratio
                     ycomp = y;% señal que se va a comprimir
                     %% implementacion compresor
                     for n = 1:lx
                         if ycomp(n) > umbral
                             sum = (ycomp(n) - umbral) / razon;
                 ycomp(n) = umbral + sum;
                 elseif ycomp(n) < -umbral
                     sum = (ycomp(n) + umbral) / razon;
                 ycomp(n) = -umbral + sum;
                 end
                     end
                     %% make up para subir la señal comprimida
                     A = 5;% ganancia en amplitud
                     ycomp = A.*ycomp;% señal filtrada y comprimida*/




                     //PROCESAMIENTO DEL DELAY L


                if (channel == 0) {

                    if (TimeDelayLSamples > 0.009f * getSampleRate())        // Solo procesar delay si TimeDelayLSamples > 0.01f*samplerate
                    {
                        readerPointerL = writerPointerL - TimeDelayLSamples;
                        if (readerPointerL < 0) {
                            readerPointerL = readerPointerL + BufferCircularSize;
                        }


                        outputCircularBufferL = WetGL_Fx * BufferCircularL[readerPointerL];
                        //outputCircularBufferL =  BufferCircularL[readerPointerL];
                        BufferCircularL[writerPointerL] = sampleL + (FeedBackL_Fx * BufferCircularL[writerPointerL]);  // escribimos el sample en la posicion del puntero

                        writerPointerL++;
                        if (writerPointerL >= BufferCircularSize) {
                            writerPointerL = 0;
                        };

                        auto outL1 = outputCircularBufferL;
                        auto outL2 = DryGL_Fx * sampleL;

                        buffer.getWritePointer(0)[i] = outL1 + outL2;
                    }
                    else
                    {
                        // Si el delay es <= 0.009f*samplerate, solo pasar la señal seca (sin delay)
                        buffer.getWritePointer(0)[i] = DryGL_Fx * sampleL;
                    }

                }

                //PROCESAMIENTO DEL DELAY R

                if (channel == 1) {

                    if (TimeDelayRSamples > 0.009f * getSampleRate()) // Solo procesar delay si TimeDelayRSamples > 0.009f
                    {

                        readerPointerR = writerPointerR - TimeDelayRSamples;
                        if (readerPointerR < 0)
                        {
                            readerPointerR = readerPointerR + BufferCircularSize;
                        }


                        outputCircularBufferR = WetGR_Fx * BufferCircularR[readerPointerR];
                        //outputCircularBufferR = BufferCircularR[readerPointerR];
                        BufferCircularR[writerPointerR] = sampleR + (FeedBackR_Fx * BufferCircularR[writerPointerR]);


                        writerPointerR++;
                        if (writerPointerR >= BufferCircularSize) {
                            writerPointerR = 0;
                        };




                        auto outR1 = outputCircularBufferR;
                        auto outR2 = DryGR_Fx * sampleR;

                        buffer.getWritePointer(1)[i] = outR1 + outR2;
                    }
                    else
                    {
                        // Si el delay es <= 1.0f, solo pasar la señal seca (sin delay)
                        // buffer.getWritePointer(1)[i] = DryGR_Fx * sampleR;
                        buffer.getWritePointer(1)[i] = DryGR_Fx * sampleR;
                    }

                }
            }
        }
    }

}

//==============================================================================
bool SDOFDelayFeedbackAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SDOFDelayFeedbackAudioProcessor::createEditor()
{
    return new SDOFDelayFeedbackAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void SDOFDelayFeedbackAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void SDOFDelayFeedbackAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SDOFDelayFeedbackAudioProcessor();
}
