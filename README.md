# Fork by VinzzF
This fork intends to upgrade the simulation environment created by [@Nelaty](https://github.com/Nelaty) to the currently latest release of the Vektoria engine V21.02. It also comes with fixes and enhancements on the simulation setup for multiple scenes.

# SimulationVektoria
Usage of this project requires the Vektoria engine (scene graph and input) and the physics engine Rumble3D.

Vektoria (V21.02 used by this repo): https://games.hs-kempten.de/vektoria  
Rumble3D: https://github.com/Nelaty/Rumble3D  
Original repository: https://github.com/Nelaty/SimulationVektoria  

## Preconditions
In theory, Vektoria versions since V20 using the DirectX12 Renderer (```m_zf.SetApiRender(Vektoria::eApiRender_DirectX12)``` in ```CGame::Init()```) do not need the DirectX SDK installation. However, this renderer is still in beta, so for best stability I recommend still using the DirectX11 renderer which requires the DirectX June 2010 SDK installation: https://www.microsoft.com/en-us/download/details.aspx?id=6812

It has to be the SDK not the Runtime Environment!

### DirectX SDK installation issues
It is possible to get the error "S1023" when installing the DirectX SDK. This can be resolved by manually deactivating two Windows updates first. PowerShell script to decativate the conflicting Windows updates: 

MsiExec.exe /passive /X{F0C3E5D1-1ADE-321E-8167-68EF0DE699A5}  
MsiExec.exe /passive /X{1D8E6291-B0D5-35EC-8441-6616F567A0F7}

## Building
1. Download the latest Vektoria engine build from: https://games.hs-kempten.de/vektoria-download
2. Copy the Vektoria library (Lib folder inside downloaded archive) to where the "ADD VEKTORIA LIB FOLDER IN THIS DIR" file is
3. Make sure all submodules of this directory are successfully cloned (Rumble3D, glm)
4. Navigate to the Rumble3D submodule and build it using the provided visual studio solution file
5. Open the visual studio solution file of this project and build it

## Acknowledgement
Thanks to [@Nelaty](https://github.com/Nelaty) for creating the initial environment and Prof. Dr. Tobias Breiner for providing the Vektoria example project and the Vektoria engine, which this project builds upon. Also for his continued support on using the Vektoria engine.
