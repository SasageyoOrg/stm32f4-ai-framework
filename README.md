<p align="center">
  <a href="" rel="noopener">
  <img width=200px height=200px src="https://i.imgur.com/RkL2KZd.png" alt="Project logo"></a>
</p>

<h1 align="center">Ricerca sulle capacità della scheda STM32F4 nell’eseguire task di Machine Learning</br><sub></sub></h1>

<div align="center">
  
![STM32CubeIDE](https://img.shields.io/badge/implementation-STM32CUBE_IDE-blue)
![UNIVPM](https://img.shields.io/badge/organization-UNIVPM-red)
![GitHub](https://img.shields.io/github/license/SasageyoOrg/stm32f4-ai-framework?color=green)
</div>

---

## 📝 Table of Contents
- [About](#about)
- [Project Topology](#project-topology)
- [STM32F4 Ad Hoc Framework](#framework)
- [Image Classification: Teachable Machine](#teachable)
- [Food Recognition: FD-MobileNet](#fd-mobilenet)
- [Human Presence Detection: MobileNet v2](#mobilenetv2)
- [Constrained Object Detection: FOMO](#fomo)
- [Built Using](#built_using)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 📋 About <a name = "about"></a>

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

## 🗂 Project Topology <a name="project-topology"></a>
```
|-- Core
|   |-- Inc/*.h
|   |-- Src/*.c
|   |-- Startup/...
|-- Drivers
|   |-- BSP/...
|   |-- CMSIS/...
|   |-- STM32F4Xxx_HAL_Driver/...
|-- FATFS
|   |-- App/...
|   |-- Target/...
|-- LIBJPEG
|   |-- App/...
|   |-- Target/...
|-- Middlewares
|   |-- ST/...
|   |-- Third_Party/...
|-- Model
|   |-- labels.txt
|   |-- model.tflite
|-- USB_HOST
|   |-- App/...
|   |-- Target/...
|-- Utilities
|   |-- Fonts/...
|-- X-CUBE-AI
|   |-- App/
|   |   |-- app_x-cube-ai-.c/.h
|   |   |-- network_config.h
|   |   |-- network_data.c/.h
|   |   |-- network_generate_report.txt
|   |   |-- network.c/.h
|   |-- constants_ai.h
|-- stm32f4-ai-framework.ioc
|-- STM32F429ZITX_FLASH.ld
|-- STM32F429ZITX_RAM.ld
```

## ⚙️ STM32F4 Ad Hoc Framework<a name="framework"></a>

<img src="https://i.imgur.com/Sbu4XXs.png" alt="Framework">

## 🤖 Image Classification: Teachable Machine <a name="teachable"></a>

<img src="https://i.imgur.com/3uVYXxL.png" alt="Teachable Machine">

## 🍱 Food Recognition: FD-MobileNet <a name="fd-mobilenet"></a>

<img src="https://i.imgur.com/66HNm24.png" alt="FD-MobileNet">

## 🚶‍♂️ Human Presence Detection: MobileNet v2 <a name="mobilenetv2"></a>

<img src="https://i.imgur.com/leyO2jR.png" alt="MobileNet v2">

## 📟 Constrained Object Detection: FOMO <a name="fomo"></a>

<img src="https://i.imgur.com/3Rw44Gd.png" alt="FOMO">

## ⛏️ Built Using <a name = "built_using"></a>

- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- [Colab](http://colab.research.google.com)
- [Edge Impulse](https://www.edgeimpulse.com)

## ✍️ Authors <a name = "authors"></a>

- Conti Edoardo [@edoardo-conti](https://github.com/edoardo-conti)
- Federici Lorenzo [@lorenzo-federici](https://github.com/lorenzo-federici)
- Melnic Andrian [@andrian-melnic](https://github.com/andrian-melnic)

## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- [W001244] - Sistemi Operativi Dedicati Class - Professor <a href="https://www.dii.univpm.it/aldo.franco.dragoni"><i>Aldo Franco Dragoni</i></a>