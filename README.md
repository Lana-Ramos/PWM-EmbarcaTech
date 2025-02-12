# Controle de Servomotor por PWM

## Descrição

**Utilizando o microcontrolador RP2040 e o módulo PWM**

Este repositório contém a atividade referente à aula de 06/02/25 da capacitação em Sistemas Embarcados do EmbartaTech referente ao controle de um servomotor através de modulação por largura de pulso (PWM) utilizando o microcontrolador Raspberry Pi Pico W (RP2040) e a ferramenta Pico SDK. O projeto simula o controle da posição de um servomotor de 180 graus, variando o ciclo de trabalho do PWM para ajustar a posição do braço do servomotor entre 0° e 180°.

A simulação é realizada utilizando o simulador Wokwi, onde a posição do servomotor é controlada por três ciclos de PWM diferentes para as posições de 0°, 90° e 180°, além de incluir uma movimentação suave entre essas posições.

## Componentes Utilizados

- **Placa Raspberry Pi Pico W (RP2040)**
- **Servomotor Micro Servo (simulado no Wokwi)**
- **LED RGB - Conectado à GPIO 12**
  
## Funcionalidades

- **Controle de posição do servomotor**: 
  - Através do PWM, ajusta-se o ciclo de trabalho para posicionar o servomotor em 0°, 90° e 180°.
  - A posição do servomotor é mantida por 5 segundos em cada uma dessas posições.
  
- **Movimentação suave do servomotor**: 
  - O servomotor realiza movimentos suaves entre 0° e 180° com incrementos de 5µs no ciclo ativo e atraso de 10ms entre cada ajuste.
  
- **Experimento com LED RGB**:
  - Através do GPIO 12, é possível observar o comportamento da iluminação do LED RGB em relação ao controle PWM aplicado ao servomotor, quando o .

## Configuração do Ambiente de Desenvolvimento

### Instalação

Antes de iniciar o programa, você vai precisar instalar na sua máquina as seguintes ferramentas:

- **Git**: [Download do Git](https://git-scm.com/downloads)
- **Visual Studio Code**: [Download do VSCode](https://code.visualstudio.com/download)
- **Compilador para C/C++**

### Dentro do VSCode

- Extensões: 
  - CMake
  - CMake Tools
  - C/C++
  - Raspberry Pi Pico
  - Wokwi

### Clonagem do Repositório

Para clonar este repositório, você deve ter o Git instalado e, em seguida, usar o comando abaixo no terminal do VSCode:

```bash
$ git clone https://github.com/Lana-Ramos/PWM-EmbarcaTech
```

Acesse a pasta do projeto:

```bash
$ cd PWM-EmbarcaTech
```

### Compile & Run

Compile o projeto utilizando a extensão Raspberry Pi Pico e envie para sua placa via USB ou realize a simulação através do arquivo `diagram.json` (necessário a extensão Wokwi para simulação).

## Status do Projeto

**Concluído**

## Autor

Lana Ramos Gomes

## Licença

Repositório feito para fins educacionais.
