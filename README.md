# SDOF DELAY FEEDBACK VST3&so SOURCE JUCE FILES

Este repositorio alberga el código fuente para compilar "SDOFDelayFeedback" VST plugin desarrollado con el framework JUCE



<img width="561" height="625" alt="image" src="https://github.com/user-attachments/assets/cd8a21bb-3df9-4216-847f-018824f356d3" />    





📦 Requisitos:  

JUCE Framework:  
https://github.com/juce-framework/JUCE  

Compilador compatible: 

Windows: Microsoft Visual Studio  
Linux: CMake + GCC/Clang

Las dependencias específicas para Linux se encuentran en la documentación oficial de JUCE:  
https://github.com/juce-framework/JUCE/blob/master/docs/Linux%20Dependencies.md


WINDOWS  

Para compilar el archivo se requiere el framework "JUCE": https://github.com/juce-framework/JUCE.  
todo lo referido a la compilación está disponible en GitHub juce-framework.  

Comenzando  

-Ejecutar ProJUCER contenido en extras de la descarga de juce 709 para Windows.  
-Crear un nuevo proyecto de tipo Plug-In->Basic con el nombre "SDOFDelayFeedback".  
-Selecciona como editor Visual Studio.  
-Comprobar rutas de JUCE a parches y los módulos necesarios agregados en el proyecto:  
<img width="1920" height="1077" alt="image" src="https://github.com/user-attachments/assets/d7047bc7-1437-4395-b400-3833b03646b8" />    

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d65648ef-ffb5-4f9c-b0b5-e8f79befe63a" />  

-Una vez creado el proyecto debería verse así:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a07c548c-495f-479d-9673-dbee34de5492" />    


-Cerrar ventana de projucer y acceder a la ruta en Windows recién creada por el proyecto.  
esta debe contener tres carpetas y el archivo de proyecto: Builds, JuceLibraryCode, Source & SDOFDelayFeedback.jucer.  
-Copiar pegar y reemplazar los archivos de la carpeta main de este repositorio en la carpeta Source del proyecto recién creado.  
-Ejecutar el archivo SDOFDelayFeedback.jucer con la aplicación ProJucer.  
-Abrir explorador de archivos del proyecto y seleccionar añadir archivos ya existentes:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b3f5711e-f4ff-4bdc-aca8-e23657cda431" />  

-Seleccionar los archivos de la carpeta source del proyecto y deberían estar todos disponibles en el explorador de archivos de Projucer:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/642b10fc-f092-4f8a-b31a-04df754f87e0" />  

-En seleccionador de exportador de projucer app, configura y ejecuta para Visual Studio.  
-Cambiar configurador de soluciones de debug a release:  

<img width="1920" height="1078" alt="image" src="https://github.com/user-attachments/assets/b6549c09-e59b-4c5e-9ed9-c1217aacebd5" />  

-Ejecutar el compilador de soluciones dando clic derecho en la solución VST3->compilar:  

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b3ad47d7-f4b0-4a8c-902e-d56d7ff130ae" />  

-Una vez compilada la solución quedará un archivo extensión .vst3 comúnmente en la ruta: SDOFDelayFeedback\Builds\VisualStudio2026\x64\Release\VST3\SDOFDelayFeedback.vst3\Contents\x86_64-win  

<img width="1126" height="25" alt="image" src="https://github.com/user-attachments/assets/9551226b-5e50-47cb-8791-341cbf426057" />  

Este archivo puede ser leído por cualquier DAW en Windows que soporte vst3.
Los mismos pasos pueden seguirse para compilar la solución stand alone y obtener una aplicación ejecutable para Windows.                  








LINUX  
Para compilar el archivo se requiere el framework "JUCE" https://github.com/juce-framework/JUCE.  
todo lo referido a la compilación está disponible en GitHub juce-framework.  
En Linux se requieren ciertas dependencias que deben ser previamente instaladas en la documentación de JUCE están disponibles las instrucciones:  
https://github.com/juce-framework/JUCE/blob/master/docs/Linux%20Dependencies.md   



Comenzando  

-Compila ProJucer utilizando make ya que JUCE en su repositorio no incluye la app ProJucer pre compilada en su version de descarga para Linux
esto está documentado por JUCE en el siguiente enlace: https://github.com/juce-framework/JUCE?tab=readme-ov-file#the-projucer.  
-Ejecutar la app Projucer compilada para Linux.   
-Crear un nuevo proyecto de tipo Plug-In->Basic con el nombre "SDOFDelayFeedback"     
-Comprobar rutas de JUCE a parches y los módulos necesarios agregados en el proyecto:  

<img width="2048" height="1536" alt="IMG_0092" src="https://github.com/user-attachments/assets/0d9579eb-aaec-4107-a2b6-bd1741328cc8" />  


-Cerrar ventana de projucer y acceder a la ruta en Linux recién creada por el proyecto.  
esta debe contener tres carpetas y el archivo de proyecto: Builds, JuceLibraryCode, Source & SDOFDelayFeedback.jucer.  
-Copiar pegar y reemplazar los archivos de la carpeta main de este repositorio en la carpeta Source del proyecto recién creado.  
-Ejecutar el archivo SDOFDelayFeedback.jucer con la aplicación ProJucer.  
-Abrir explorador de archivos del proyecto y seleccionar añadir archivos ya existentes  
-Seleccionar los archivos de la carpeta source del proyecto y quedarán todos disponibles en el explorador de archivos de Projucer:  
<img width="2048" height="1536" alt="IMG_0093" src="https://github.com/user-attachments/assets/022823ca-363c-4ddf-abab-ed05020b844c" />  


-En seleccionador de exportador de projucer app no podrás seleccionar compilador por lo que solo debes cerrar la ventana de projucer  
para ejecutar un compilador por consola de comandos en la ruta indicada, abriendo un terminal en la ubicacion del archivo LinuxMakefile:    
<<SDOF DELAY LINUX/SDOFDelayFeedback/Builds/LinuxMakefile/>>  
<img width="2048" height="1536" alt="IMG_0091" src="https://github.com/user-attachments/assets/c1446511-1560-4bd0-99fa-59b5fb52c8ae" />  

-Escribe el comando: make en la terminal:  

<img width="2048" height="1536" alt="IMG_0090" src="https://github.com/user-attachments/assets/0e197f95-b273-42f8-9d89-65e13310b899" />  
-Esto compilará la solucion en todos los exportadores que fueron seleccionados en el proyecto configurado en Projucer App, quedará un archivo extensión .so comúnmente en la ruta: 
<</SDOFDelayFeedback/Builds/LinuxMakefile/build/SDOFDelayFeedback.vst3/Contents/aarch64-linux/SDOFDelayFeedback.so>>  

<img width="930" height="164" alt="image" src="https://github.com/user-attachments/assets/8eff740f-87d3-478c-84a0-4883cd0f5a07" />  


Este archivo puede ser leído por cualquier DAW en LINUX que soporte so.  
Los mismos pasos compilan la solución standalone creando un ejecutable para linux.        



-Elaborado bajo licencia GNU: SDOF LAB por -Pablo Iván Gutiérrez Legent-

