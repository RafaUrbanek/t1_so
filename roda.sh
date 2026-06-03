#!/bin/bash

# Compila o projeto
echo "Executando make"
make

# Verifica se a compilação foi bem-sucedida
if [ $? -ne 0 ]; then
    echo "Erro na compilação."
    exit 1
fi

# Valores de número de processos
for n in 1 5 10 20
do
    if [ "$n" -eq 1 ]; then
        arquivo="teste_${n}_processo.log"
    else
        arquivo="teste_${n}_processos.log"
    fi

    echo "Executando ./trab $n"
    ./trab "$n" > "$arquivo" 2>&1

    echo "Saída salva em $arquivo"
done

# Limpeza
echo "Executando make clean"
make clean

echo "Testes concluídos."