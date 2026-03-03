# SDOF DELAY JUCEFiles

Este repositorio alberga el codigo fuente para compilar "SDOFDelay" vst plugin desarrollado con el framwork JUCE
contiene los archivos para Windows&Linux  

📦 Requisitos  

JUCE Framework  
https://github.com/juce-framework/JUCE  

Compilador compatible: 

Windows: Microsoft Visual Studio  
Linux: CMake + GCC/Clang

Las dependencias específicas para Linux se encuentran en la documentación oficial de JUCE:
https://github.com/juce-framework/JUCE/blob/master/docs/Linux%20Dependencies.md


WINDOWS
Para compilar el archivo se requiere el framework "JUCE" https://github.com/juce-framework/JUCE.  
todo lo referido a la compilación esta disponible en github juce-framework.  

Comenzando  
-Ejecutar ProJUCER contenido en extras de las descarga de juce 709 para win.  
-Crear un nuevo proyecto de tipo Plug-In->Basic con el nombre "SDOFDelayFeedback".  
-Selecciona como editor Visual Studio.  
-Comprobar rutas de JUCE a modulos.
<img width="1920" height="1077" alt="image" src="https://github.com/user-attachments/assets/d7047bc7-1437-4395-b400-3833b03646b8" />    
  
-Una vez creado el proyecto debería verse así:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a07c548c-495f-479d-9673-dbee34de5492" />    


-Cerrar ventana de projucer y acceder a la ruta en windows recien creada por el proyecto.  
esta debe contener tres carpetas y el archivo de proyecto: Builds, JuceLibraryCode, Source & SDOFDelayFeedback.jucer.  
-Copiar pegar y reemplazar los archivos de la carpeta "Source" de este repositorio en la carpeta "Source" del proyecto recien creado.  
-Ejecutar el archivo SDOFDelayFeedback.jucer con la aplicacion ProJucer.  
-Abrir explorador de archivos del proyecto y seleccionar añadir archivos ya existentes:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b3f5711e-f4ff-4bdc-aca8-e23657cda431" />  

-Seleccionar los 7 archivos de la carpeta source del proyecto y deberian estar todos disponibles en el explorador de archivos de Projucer:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/642b10fc-f092-4f8a-b31a-04df754f87e0" />

-En seleccionador de exportador de projucer app, configura y ejecuta para Visual Studio.  
-Cambiar configurador de soluciones de debug a release:  

<img width="1920" height="1078" alt="image" src="https://github.com/user-attachments/assets/b6549c09-e59b-4c5e-9ed9-c1217aacebd5" />  

-Ejecutar el compilador de soluciones dando click derecho en la solucion VST3->compilar:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b3ad47d7-f4b0-4a8c-902e-d56d7ff130ae" />

-Una vez compilada la solucion quedará un archivo extension .vst3 comunmente en la ruta: SDOFDelayFeedback\Builds\VisualStudio2026\x64\Release\VST3\SDOFDelayFeedback.vst3\Contents\x86_64-win  
<img width="1126" height="25" alt="image" src="https://github.com/user-attachments/assets/9551226b-5e50-47cb-8791-341cbf426057" />

Este archivo puede ser leído por cualquier DAW en win que soporte vst3.
Los mismos pasos pueden seguirce para compilar la solución stand alone y obtener una aplicacion ejecutable para windows.






------LINUX------  
Para compilar el archivo se requiere el framework "JUCE" https://github.com/juce-framework/JUCE.  
todo lo referido a la compilación esta disponible en github juce-framework.  
En linux se requieren ciertas dependencias que deben ser previamente instaladas en la documentacion de JUCE están disponibles las instrucciones:  
https://github.com/juce-framework/JUCE/blob/master/docs/Linux%20Dependencies.md.  


----Comenzando----  

-Compila ProJucer utilizando Cmake
-Ejecutar la app Projucer compilada para linux 
-Crear un nuevo proyecto de tipo Plug-In->Basic con el nombre "SDOFDelayFeedback".  
-Selecciona como editor Visual Studio.  
-Comprobar rutas de JUCE a modulos.
<img width="1920" height="1077" alt="image" src="https://github.com/user-attachments/assets/d7047bc7-1437-4395-b400-3833b03646b8" />    
  
-Una vez creado el proyecto debería verse así:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a07c548c-495f-479d-9673-dbee34de5492" />    






