/*
   ================================================================================================================================================

    SDOF DELAY FEEDBACK STEREO 
                                                  Por: Pablo Ivan Gutierrez Legent
    (PluginEditor.cpp)                            fecha: 2024-2025               
  =================================================================================================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <atomic>
#include <iostream> 

//==============================================================================
SDOFDelayFeedbackAudioProcessorEditor::SDOFDelayFeedbackAudioProcessorEditor (SDOFDelayFeedbackAudioProcessor& p,
    juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState(vts)
{


    // Cargar la imagen de fondo
    backgroundImage = juce::ImageFileFormat::loadFrom(BinaryData::backgroundImage_png, BinaryData::backgroundImage_pngSize);


    //setSize (450, 500);
    setSize(backgroundImage.getWidth(), backgroundImage.getHeight());

    // Parametros graficos

    // time Delay L
    TimeDelayL.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    TimeDelayL.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 30, 12);
    addAndMakeVisible(&TimeDelayL);
    TimeDelayL.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    TimeDelayL.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkgoldenrod);
    TimeDelayL.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkkhaki);
    TimeDelayL.setRange(0.0f, 1.9f);
    TimeDelayLAtt.reset(new VTS_Slider_Attachment(valueTreeState, "TimeDelayL", TimeDelayL));

    //
    addAndMakeVisible(&TimeDelayLLabel);
    TimeDelayLLabel.attachToComponent(&TimeDelayL, false);
    TimeDelayLLabel.setJustificationType(juce::Justification::centredBottom);
    TimeDelayLLabel.setText("Delay L", juce::dontSendNotification);
    TimeDelayLLabel.setColour(juce::Label::textColourId, juce::Colours::white);

    // time Delay R
    TimeDelayR.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    TimeDelayR.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 30, 12);
    addAndMakeVisible(&TimeDelayR);
    TimeDelayR.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    TimeDelayR.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkgoldenrod);
    TimeDelayR.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkkhaki);
    TimeDelayR.setRange(0.0f, 1.9);
    TimeDelayRAtt.reset(new VTS_Slider_Attachment(valueTreeState, "TimeDelayR", TimeDelayR));
    //
    addAndMakeVisible(&TimeDelayRLabel);
    TimeDelayRLabel.attachToComponent(&TimeDelayR, false);
    TimeDelayRLabel.setJustificationType(juce::Justification::centredBottom);
    TimeDelayRLabel.setText("Delay R", juce::dontSendNotification);
    TimeDelayRLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    //DryGainL
    //DryGL.setTitle("DryGainL");
    DryGL.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    DryGL.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    addAndMakeVisible(&DryGL);
    DryGL.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    DryGL.setColour(juce::Slider::trackColourId, juce::Colours::indigo);
    DryGL.setColour(juce::Slider::backgroundColourId, juce::Colours::darkkhaki);
    DryGL.setRange(0.0f, 0.9f);
    DryGLAtt.reset(new VTS_Slider_Attachment(valueTreeState, "DryGL", DryGL));
    //
    addAndMakeVisible(&DryGLLabel);
    DryGLLabel.attachToComponent(&DryGL, false);
    DryGLLabel.setJustificationType(juce::Justification::centredBottom);
    DryGLLabel.setText("In", juce::dontSendNotification);
    DryGLLabel.setColour(juce::Label::textColourId, juce::Colours::darkkhaki);
    //WetGainL
    WetGL.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    WetGL.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    addAndMakeVisible(&WetGL);
    WetGL.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    WetGL.setColour(juce::Slider::trackColourId, juce::Colours::darkgoldenrod);
    WetGL.setColour(juce::Slider::backgroundColourId, juce::Colours::darkkhaki);
    WetGL.setRange(0.0f, 0.9f);
    WetGLAtt.reset(new VTS_Slider_Attachment(valueTreeState, "WetGL", WetGL));
    //
    addAndMakeVisible(&WetGLLabel);
    WetGLLabel.attachToComponent(&WetGL, false);
    WetGLLabel.setJustificationType(juce::Justification::centredBottom);
    WetGLLabel.setText("Out", juce::dontSendNotification);
    WetGLLabel.setColour(juce::Label::textColourId, juce::Colours::darkkhaki);
    //DryGainR
    DryGR.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    DryGR.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    addAndMakeVisible(&DryGR);
    DryGR.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    DryGR.setColour(juce::Slider::trackColourId, juce::Colours::indigo);
    DryGR.setColour(juce::Slider::backgroundColourId, juce::Colours::darkkhaki);
    DryGR.setRange(0.0f, 0.9f);
    DryGRAtt.reset(new VTS_Slider_Attachment(valueTreeState, "DryGR", DryGR));
    //
    addAndMakeVisible(&DryGRLabel);
    DryGRLabel.attachToComponent(&DryGR, false);
    DryGRLabel.setJustificationType(juce::Justification::centredBottom);
    DryGRLabel.setText("In", juce::dontSendNotification);
    DryGRLabel.setColour(juce::Label::textColourId, juce::Colours::darkkhaki);
    // WetGainR
    WetGR.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    WetGR.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    addAndMakeVisible(&WetGR);
    WetGR.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    WetGR.setColour(juce::Slider::trackColourId, juce::Colours::darkgoldenrod);
    WetGR.setColour(juce::Slider::backgroundColourId, juce::Colours::darkkhaki);
    WetGR.setRange(0.0f, 0.9f);
    WetGRAtt.reset(new VTS_Slider_Attachment(valueTreeState, "WetGR", WetGR));
    //
    addAndMakeVisible(&WetGRLabel);
    WetGRLabel.attachToComponent(&WetGR, false);
    WetGRLabel.setJustificationType(juce::Justification::centredBottom);
    WetGRLabel.setText("Out", juce::dontSendNotification);
    WetGRLabel.setColour(juce::Label::textColourId, juce::Colours::darkkhaki);

    //FeedBackGainL
    FeedBackGL.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    FeedBackGL.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    addAndMakeVisible(&FeedBackGL);
    FeedBackGL.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    FeedBackGL.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkgoldenrod);
    FeedBackGL.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkkhaki);
    FeedBackGL.setRange(0.0f, 0.9f);
    FeedBackGLAtt.reset(new VTS_Slider_Attachment(valueTreeState, "FeedBackGL", FeedBackGL));
    //
    addAndMakeVisible(&FeedBackGLLabel);
    FeedBackGLLabel.attachToComponent(&FeedBackGL, false);
    FeedBackGLLabel.setJustificationType(juce::Justification::centredBottom);
    //FeedBackGLLabel.setBorderSize(juce::BorderSize<int>(0, 0, 0, 25));
    FeedBackGLLabel.setText("FeedBack", juce::dontSendNotification);
    FeedBackGLLabel.setColour(juce::Label::textColourId, juce::Colours::darkgoldenrod);

    //FeedBackGainR
    FeedBackGR.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    FeedBackGR.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    addAndMakeVisible(&FeedBackGR);
    FeedBackGR.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    FeedBackGR.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkgoldenrod);
    FeedBackGR.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkkhaki);
    FeedBackGR.setRange(0.0f, 0.9f);
    FeedBackGRAtt.reset(new VTS_Slider_Attachment(valueTreeState, "FeedBackGR", FeedBackGR));
    //
    addAndMakeVisible(&FeedBackGRLabel);
    FeedBackGRLabel.attachToComponent(&FeedBackGR, false);
    FeedBackGRLabel.setJustificationType(juce::Justification::centredBottom);
    //FeedBackGRLabel.setBorderSize(juce::BorderSize<int>(0, 0, 0, 25));
    FeedBackGRLabel.setText("FeedBack", juce::dontSendNotification);
    FeedBackGRLabel.setColour(juce::Label::textColourId, juce::Colours::darkgoldenrod);


}

SDOFDelayFeedbackAudioProcessorEditor::~SDOFDelayFeedbackAudioProcessorEditor()
{
}

//==============================================================================
void SDOFDelayFeedbackAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::black);

    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText(">>Pablo's DelayFeedBack<<", getLocalBounds(), juce::Justification::centredTop, 1);
    g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), 0, 0, getWidth(), getHeight());
}

void SDOFDelayFeedbackAudioProcessorEditor::resized()
{
    auto k = 0.05;
    auto borde_izq = k * getWidth();
    auto borde_sup = k * getHeight();
    auto w = (getWidth() - (2 * borde_izq)) / 2;            //margen util, mitad horizontal ancho q usa un objt
    auto h = (getHeight() - (2 * borde_sup)) / 3;           //margen util, mitad vertical   alto

    //posiciones objetos
    auto x1 = borde_izq;
    auto y1 = borde_sup;

    auto x2 = x1 + w;
    auto y2 = borde_sup;

    auto x3 = x1;
    auto y3 = y1 + h;

    auto x4 = x1 + (w / 2);
    auto y4 = y1 + h;

    auto x5 = x2;
    auto y5 = y1 + h;

    auto x6 = x5 + (w / 2);
    auto y6 = y1 + h;

    auto x7 = x1;
    auto y7 = y3 + h;

    auto x8 = x5;
    auto y8 = y5 + h;

    // Posiciones de los botones 


    TimeDelayL.setBounds(x1, y1, w, h);
    TimeDelayR.setBounds(x2, y2, w, h);
    DryGL.setBounds(x3, y3, w / 2, h);
    WetGL.setBounds(x4, y4, w / 2, h);
    DryGR.setBounds(x5, y5, w / 2, h);
    WetGR.setBounds(x6, y6, w / 2, h);
    FeedBackGL.setBounds(x7, y7, w, h);
    FeedBackGR.setBounds(x8, y8, w, h);
}
