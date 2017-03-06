# zettaconf

Zetta(c) (and rebranded) security cameras configuration utility

## Getting Started

These instructions will get you zettaconf utility up and running on your local machine.

### Prerequisites

To build zettaconf from source, the following tools are needed:

 * make
 * gcc
 
### Installing

To build and install zettaconf execute the following:

    $ make
    $ sudo make install

### Usage

    $ zettaconf --print
    $ zettaconf --help
    $ zettaconf [--videoquality <low|medium|high>]
      [--resolution <320x240|640x480|640x360|1280x720>]
      [--motiondetect <off|low|medium|high>]
      [--showtimestamp <off|on>]
      [--circularrec <off|on>]
      [--framerate  <low|high>]
      [--splitfiletime <10|15|20|30|60>]
      [--daynightmode <day|night|auto>]
      [--orientation <normal|flip>]
      [--autostartmode <off|absent|present|present_start|scheduled>]
      [--voicedetect <off|low|medium|high>]
      [--voicerec <off|on>]
      [--vibrdetect <off|low|medium|high>]
      [--standbymode <psave|fast>]
      [--aliveduration <5|2>]
      [--led <off|on>]
      [--lighting <50hz|60hz|outdoor>]
      [--extintype <off|no|nc>]
      [--extouttype <off|no|nc>]
      [--buzzarduration <off|rec|5|1>]
      [--sensorsens <low|medium|high>]
      [--pir <off|on>]
      [--synctime]
