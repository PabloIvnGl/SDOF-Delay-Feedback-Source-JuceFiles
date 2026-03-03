/*
   ==============================================================================

    SDOF DELAY FEEDBACK STEREO 
                                                Por: Pablo Ivan Gutierrez Legent
                                                                fecha: 2024-2025               
  =========================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include <atomic>
#include <iostream> 

//==============================================================================
/**
*/
class SDOFDelayFeedbackAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SDOFDelayFeedbackAudioProcessorEditor (SDOFDelayFeedbackAudioProcessor& p, juce::AudioProcessorValueTreeState& vts);
    ~SDOFDelayFeedbackAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    typedef juce::AudioProcessorValueTreeState::SliderAttachment VTS_Slider_Attachment;

    //Imagen
    juce::Image backgroundImage; // Agrega esta linea

private:

    //Estados 
    juce::AudioProcessorValueTreeState& valueTreeState;
    //Declaraciones propias
    juce::Slider TimeDelayL;
    juce::Slider TimeDelayR;
    juce::Slider DryGL;
    juce::Slider WetGL;
    juce::Slider DryGR;
    juce::Slider WetGR;
    juce::Slider FeedBackGL;
    juce::Slider FeedBackGR;

    juce::Label TimeDelayLLabel;
    juce::Label TimeDelayRLabel;
    juce::Label DryGLLabel;
    juce::Label WetGLLabel;
    juce::Label DryGRLabel;
    juce::Label WetGRLabel;
    juce::Label FeedBackGLLabel;
    juce::Label FeedBackGRLabel;

    std::unique_ptr<VTS_Slider_Attachment> TimeDelayLAtt;
    std::unique_ptr<VTS_Slider_Attachment> TimeDelayRAtt;
    std::unique_ptr<VTS_Slider_Attachment> DryGLAtt;
    std::unique_ptr<VTS_Slider_Attachment> WetGLAtt;
    std::unique_ptr<VTS_Slider_Attachment> DryGRAtt;
    std::unique_ptr<VTS_Slider_Attachment> WetGRAtt;
    std::unique_ptr<VTS_Slider_Attachment> FeedBackGLAtt;
    std::unique_ptr<VTS_Slider_Attachment> FeedBackGRAtt;





    SDOFDelayFeedbackAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SDOFDelayFeedbackAudioProcessorEditor)
};
