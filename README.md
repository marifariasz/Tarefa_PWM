# Controle de Servomotor por PWM - RP2040  

Este repositório contém a implementação da tarefa sobre **Controle de Servomotor por PWM**, utilizando o **RP2040** e o simulador **Wokwi**. O objetivo é ajustar o ângulo do servomotor por meio de sinais PWM.  

## 👷🏻‍♀️ Desenvolvedora
**Mariana Farias da Silva**


## 📌 Objetivos  

- Compreender e aplicar **modulação por largura de pulso (PWM)** no RP2040.  
- Simular o controle de **servomotor** no **Wokwi**.  
- Implementar diferentes cíclos de trabalho para variar o ângulo do servomotor.  
- Criar um algoritmo para movimentação suave do servo entre **0 e 180 graus**.  
- Testar o impacto do PWM na iluminação do LED RGB.  

## 🛠 Componentes Utilizados  

- **Microcontrolador Raspberry Pi Pico W**  
- **Servomotor - Wokwi**  
- **LED RGB - GPIO 12**  

## 🚀 Funcionalidades  

1. **Definição da Frequência PWM**  
   - Configurar a **GPIO 22** com uma frequência de aproximadamente **50Hz** (período de 20ms).  

2. **Posicionamento do Servo**  
   - **180 graus:** Ciclo ativo **2.400µs** (0,12% Duty Cycle). Aguardar 5s.  
   - **90 graus:** Ciclo ativo **1.470µs** (0,0735% Duty Cycle). Aguardar 5s.  
   - **0 graus:** Ciclo ativo **500µs** (0,025% Duty Cycle). Aguardar 5s.  

3. **Movimentação Periódica**  
   - Movimentação suave entre **0 e 180 graus**, com incremento de **±5µs** e atraso de **10ms**.  

4. **Experimento com LED RGB**  
   - Testar o comportamento do LED RGB **(GPIO 12)** ao executar o código PWM.  

## 📚 Estrutura do Repositório  
```
📺 Controle-Servo-PWM  
 ├️ 📂 src                  # Código-fonte do projeto  
 ├️ 📂 docs                 # Documentação e referências  
 ├️ 📂 assets               # Imagens e vídeos de demonstração  
 ├️ 📚 README.md            # Este arquivo  
 └️ 📚 pwm_control.c       # Código principal  
```

## 🎥 Entrega  
- **Código-fonte**: Disponível neste repositório.  
- **Vídeo de demonstração**: [Link para o vídeo (YouTube/Drive)](https://youtube.com/shorts/wIxscoSRYZ4).  
