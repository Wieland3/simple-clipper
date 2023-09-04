/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ClipperAudioProcessorEditor::ClipperAudioProcessorEditor (ClipperAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    // Set up the knob
    
    // Set up the gain slider
    gainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
    gainSlider.setMouseDragSensitivity(444);
    gainSlider.setColour(juce::Slider::thumbColourId, juce::Colour(248, 241, 255));
    gainSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(248, 241, 255));
    gainSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(30, 30, 30));
    gainSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(248, 241, 255));
    addAndMakeVisible(gainSlider);
    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
            audioProcessor.apvts, "gain", gainSlider);
    
    thresholdSlider.setSliderStyle(juce::Slider::LinearVertical);
    thresholdSlider.setMouseDragSensitivity(444);
    thresholdSlider.setColour(juce::Slider::thumbColourId, juce::Colour(248, 241, 255));
    thresholdSlider.setColour(juce::Slider::backgroundColourId, juce::Colour(248, 241, 255));
    thresholdSlider.setColour(juce::Slider::trackColourId, juce::Colour(30, 30, 30));
    thresholdSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(248, 241, 255));
    
    thresholdSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
    addAndMakeVisible(thresholdSlider);
    thresholdSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
            audioProcessor.apvts, "threshold", thresholdSlider);

    setSize (400, 300);
}

ClipperAudioProcessorEditor::~ClipperAudioProcessorEditor()
{
}

//==============================================================================
void ClipperAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(57, 61, 63));
    //57, 61, 63
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void ClipperAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() - 350, getHeight() / 2 - 100, 200, 200);
    thresholdSlider.setBounds(getWidth() - 200, getHeight() / 2 - 100, 200, 200);
}
