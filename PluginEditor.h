#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    const double mnRg;
    const double mxRg;

    juce::Slider GnSldr;
    juce::Range<double> SlRg;

    void sliderValueChanged(juce::Slider* slider) override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
