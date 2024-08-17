# unity-unsplash
Removes Unity's splash screen & watermark w/ DLL injection.

Only tested on Unity 2022.3.17 Mono & IL2CPP Windows non-Development (Master) builds.

Unity 2020/2019 players may work as well, but not guaranteed.

## Usage
- You can download the latest release from the [releases](https://github.com/mos9527/unity-unsplash/releases) and put the DLL file (named `winmm.dll`) in the game's root directory.
- Or, you can rename the DLL file to `unity-unsplash.asi` and put it with [Ultimate-ASI-Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) inside the said directory, alongside any other ASI plugins you may have.

## References
SigScan code from:
- https://github.com/blueskythlikesclouds/DivaModLoader

