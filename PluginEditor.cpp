#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 600);

    MyGainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    MyGainSlider.setRange(0.0, 1.0);
    MyGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    MyGainSlider.setPopupDisplayEnabled(true, true, this);
    MyGainSlider.setTextValueSuffix("Volume");
    MyGainSlider.setValue(0.5);

    addAndMakeVisible(MyGainSlider);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Gain", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    MyGainSlider.setBounds(40, 30, 20, getHeight() - 60);
}
