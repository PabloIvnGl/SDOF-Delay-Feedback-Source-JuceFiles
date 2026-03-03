/*
    ==============================================================================

    SDOF DELAY FEEDBACK STEREO 
                                                Por: Pablo Ivan Gutierrez Legent
                                                                fecha: 2024-2025               
  ===============================================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "tools.h"

//================================================================================
/**
*/
class SDOFDelayFeedbackAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    SDOFDelayFeedbackAudioProcessor();
    ~SDOFDelayFeedbackAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //Vectores Rampa para Gains

    WindowVector* vector_1 = nullptr;
    WindowVector* vector_2 = nullptr;
    WindowVector* vector_3 = nullptr;
    WindowVector* vector_4 = nullptr;
    WindowVector* vector_5 = nullptr;
    WindowVector* vector_6 = nullptr;
    WindowVector* vector_7 = nullptr;
    WindowVector* vector_8 = nullptr;

private:
    //==============================================================================


    juce::AudioProcessorValueTreeState parameters;

    //timeDelayL
    float PreviousTimeDelayL;
    std::atomic<float>* CurrentTimeDelayL = nullptr;

    //timeDelayR
    float PreviousTimeDelayR;
    std::atomic<float>* CurrentTimeDelayR = nullptr;

    //Dry Wet L
    float PreviousDryGL;
    std::atomic<float>* CurrentDryGL = nullptr;
    float PreviousWetGL;
    std::atomic<float>* CurrentWetGL = nullptr;

    //Dry Wet R
    float PreviousDryGR;
    std::atomic<float>* CurrentDryGR = nullptr;
    float PreviousWetGR;
    std::atomic<float>* CurrentWetGR = nullptr;

    //FeedBackGainL
    float PreviousFeedBackGL;
    std::atomic<float>* CurrentFeedBackGL = nullptr;

    //FeedBackGainR
    float PreviousFeedBackGR;
    std::atomic<float>* CurrentFeedBackGR = nullptr;



    //// BufferCircular para Delay
    //FeedbackDelay* BufferDelayL;
    //FeedbackDelay* BufferDelayR;


	static const int BufferCircularSize = 44100 * 4;                         // 44100 muestras por segundo (44100 -> 60) (176400 -> x) --> x = (176400*1)/44100             176.400 muestras        
    float BufferCircularL[BufferCircularSize] = { 0.0f };                   //mayor tamaue el buffer de entrada para que el tiemmpo de delay pueda sonar  
    float BufferCircularR[BufferCircularSize] = { 0.0f };                  //mayor tamao que el buffer de entrada para que el tiemmpo de delay pueda sonar  
    int readerPointerL = 0;
    int readerPointerR = 0;
    int writerPointerL = 0;                                              // dos punteros para stereo 
    int writerPointerR = 0;


    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SDOFDelayFeedbackAudioProcessor)
};