#include "PluginProcessor.h"
#include "PluginEditor.h"

/**
 * TODO: Get a better font for the text in the UI of the plugin and better size
 * TODO: Possible slider UI improvement, see all options gave by JUCE
 * TODO: Improve color of the plugin
 * TODO: Double check the feel of the plugin, probably might need some log interpolation
*/

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p),
    mnRg(-62.0),
    mxRg(25.0)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 600);


    SlRg = juce::Range<double>(mnRg, mxRg); // set the range of the slider

    // UI elements
    GnSldr.setSliderStyle(juce::Slider::LinearBarVertical);
    GnSldr.setRange(SlRg, 0.01);
    GnSldr.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    GnSldr.setPopupDisplayEnabled(true, true, this);
    GnSldr.setTextValueSuffix("Gain");
    GnSldr.setValue(0.0);

    addAndMakeVisible(GnSldr);
    GnSldr.addListener(this);
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

    // TODO: Set a better solution for the resizing of the slider
    GnSldr.setBounds(40, 30, 20, getHeight() - 60);
}

void AudioPluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider){
    processorRef.GnVl = (float)GnSldr.getValue();
}