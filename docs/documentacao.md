# Documentação Técnica – TrackSence

## Sistema de Contagem de Pessoas com ESP32

---

## 1. Introdução

O presente documento descreve o desenvolvimento do sistema TrackSence, um sistema embarcado responsável por realizar a contagem de pessoas que entram e saem de um ambiente utilizando sensores de movimento conectados a um microcontrolador ESP32. O sistema realiza a detecção em tempo real e exibe a quantidade de pessoas presentes em um display LCD.

O projeto foi desenvolvido com fins acadêmicos para a disciplina de Sistemas Embarcados.

---

## 2. Objetivo do Projeto

O objetivo do projeto é desenvolver um sistema embarcado capaz de:

* Detectar movimento de pessoas
* Identificar a direção do movimento (entrada ou saída)
* Contabilizar o número de pessoas no ambiente
* Exibir o número de pessoas em um display LCD
* Registrar eventos no monitor serial
* Simular o funcionamento utilizando o Wokwi

---

## 3. Descrição do Sistema

O sistema TrackSence é composto por dois sensores de movimento posicionados na entrada de um ambiente. A lógica do sistema baseia-se na ordem de ativação dos sensores para identificar se a pessoa está entrando ou saindo.

Se o Sensor A for ativado primeiro e depois o Sensor B, o sistema interpreta que uma pessoa entrou no ambiente.
Se o Sensor B for ativado primeiro e depois o Sensor A, o sistema interpreta que uma pessoa saiu do ambiente.

O valor do contador é atualizado e exibido em um display LCD 16x2 com comunicação I2C.

---

## 4. Componentes Utilizados

Os principais componentes utilizados no projeto são:

* Microcontrolador ESP32
* 2 Sensores de movimento PIR
* Display LCD 16x2 com módulo I2C
* Cabos Jumpers
* Computador para programação
* Simulador Wokwi
* Linguagem de programação C++

---

## 5. Arquitetura do Sistema

O sistema é composto pelos seguintes módulos:

* Módulo de Sensoriamento (Sensores PIR)
* Módulo de Processamento (ESP32)
* Módulo de Saída (Display LCD)
* Módulo de Monitoramento (Serial Monitor)

Fluxo do sistema:

1. Sensores detectam movimento
2. ESP32 lê os sinais digitais
3. O sistema identifica a direção do movimento
4. O contador é atualizado
5. O valor é exibido no LCD
6. O evento é registrado no Serial Monitor

---

## 6. Funcionamento do Algoritmo

O algoritmo principal do sistema segue os seguintes passos:

1. Ler o estado dos sensores
2. Verificar se o Sensor A foi ativado
3. Verificar se o Sensor B foi ativado em seguida
4. Incrementar o contador
5. Verificar se o Sensor B foi ativado primeiro
6. Verificar se o Sensor A foi ativado em seguida
7. Decrementar o contador
8. Impedir valores negativos
9. Exibir o contador no LCD
10. Registrar o evento no Serial Monitor

---

## 7. Estrutura de Pastas do Projeto

A organização do projeto foi estruturada da seguinte forma:

TrackSence/
│
├── src/
│   └── tracksence.ino
│
├── images/
│   └── circuito.png
│
├── docs/
│   └── documentacao.md
│
└── README.md

---

## 8. Possíveis Aplicações

O sistema desenvolvido pode ser utilizado em:

* Controle de fluxo de pessoas em lojas
* Controle de lotação em eventos
* Monitoramento de bibliotecas
* Restaurantes
* Salas de aula
* Prédios comerciais
* Automação predial
* Sistemas de segurança

---

## 9. Melhorias Futuras

Algumas melhorias que podem ser implementadas futuramente:

* Envio de dados via WiFi
* Armazenamento em banco de dados
* Dashboard Web
* Aplicativo mobile
* Gráficos de fluxo de pessoas
* Sistema de limite máximo de pessoas
* Alertas automáticos
* Uso de sensores infravermelho de barreira
* Integração com IoT

---

## 10. Conclusão

O projeto TrackSence demonstrou a aplicação de sistemas embarcados para monitoramento e contagem de pessoas utilizando sensores de movimento e microcontroladores. O sistema foi capaz de detectar a direção do movimento e manter um contador atualizado em tempo real, mostrando os resultados em um display LCD e no monitor serial.

O projeto permitiu aplicar conceitos de programação embarcada, leitura de sensores, processamento de sinais digitais e comunicação com dispositivos de saída.

---

## 11. Autor

Alyson Thadeu
Anthony Rychard
Maria Heloísa
Projeto de Sistemas Embarcados
TrackSence – Sistema de Contagem de Pessoas
