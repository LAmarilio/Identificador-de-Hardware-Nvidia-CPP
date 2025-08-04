## Identificador de Hardware com NVAPI

Este projeto é uma ferramenta leve, desenvolvida em C++, que exibe informações detalhadas sobre CPU, GPU NVIDIA e memória RAM do sistema. Utiliza a biblioteca proprietária **NVAPI** para obter dados diretamente da placa de vídeo.

---

## Funcionalidades

- Detecção do modelo da CPU e número de núcleos
- Identificação da GPU NVIDIA (caso presente)
- Versão do driver NVIDIA e branch atual
- Memória RAM total disponível

---

## Requisitos

- **Sistema Windows**
- **GPU NVIDIA** instalada
- **Drivers da NVIDIA atualizados**

> O programa exibirá uma mensagem de erro caso sua GPU não seja NVIDIA ou os drivers estejam desatualizados.

---

## Como usar

1. Baixe o executável na seção [Releases](https://github.com/LAmarilio/Identificador-de-Hardware-Nvidia-CPP/releases/tag/v1.0.0).
Observação: o seu navegador e anti-virus podem apontar o arquivo como não seguro, mesmo assim eles permitem que você faça o download e execute, entretanto, confirmando de forma manual.
2. Execute o programa, ele não solicita para ser executado como administrador.
3. Os dados serão exibidos no terminal.

---

## Compilação manual (opcional)

Caso queira compilar o código por conta própria:

- Tenha o **Visual Studio** instalado com suporte a C++
- Inclua o arquivo `nvapi.h` e configure a referência à `nvapi.lib` na solução
- Compile em **modo Release** para gerar o `.exe`
