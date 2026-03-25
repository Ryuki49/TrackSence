📊 TrackSence – Sistema de Contagem de Pessoas com ESP32
📌 Descrição

O TrackSence é um sistema de monitoramento de fluxo de pessoas utilizando ESP32, sensores de presença e display LCD I2C.
O sistema identifica se a pessoa entrou ou saiu do ambiente com base na ordem de ativação dos sensores, mantendo um contador atualizado em tempo real.

Este projeto pode ser utilizado em:

Lojas
Bibliotecas
Eventos
Restaurantes
Salas de aula
Controle de lotação
🧠 Funcionamento do Sistema

O sistema utiliza dois sensores de presença posicionados na entrada do ambiente.

A lógica funciona assim:

Ordem de ativação	Ação
Sensor A → Sensor B	Pessoa entrou
Sensor B → Sensor A	Pessoa saiu

Isso evita contagens erradas.

O número de pessoas é:

Mostrado no display LCD
Enviado para o Serial Monitor
🧰 Componentes Utilizados
ESP32
2 Sensores PIR (movimento)
Display LCD 16x2 com I2C
Jumpers
Simulador Wokwi
🔌 Ligações do Circuito
Componente	Conexão ESP32
Sensor A OUT	GPIO 12
Sensor B OUT	GPIO 5
LCD SDA	GPIO 21
LCD SCL	GPIO 22
VCC	5V
GND	GND
