# https://colab.research.google.com/drive/1OBaT0wTHJOuGWGijoBBEuBJ5zTA-NP8U?usp=sharing

import matplotlib.pyplot as plt

def ler_dados(nome_arquivo):
    tamanhos = []
    tempos = []
    with open(nome_arquivo, 'r') as arquivo:
        for linha in arquivo:
            tamanho, tempo = map(int, linha.split())
            tamanhos.append(tamanho)
            tempos.append(tempo)
    return tamanhos, tempos

arquivos = [
    'ins.dat',
    'selec.dat',
    'flut.dat',
    'heap.dat',
]

titulos = [
    'Insercao',
    'Selecao',
    'Flutuacao',
    'Heapsort',
]

for i, arquivo in enumerate(arquivos):
    tamanhos, tempos = ler_dados(arquivo)
    plt.plot(tamanhos, tempos, label=titulos[i])

plt.xlabel('N')
plt.ylabel('Tempo (microssegundos)')
plt.legend()
plt.title('Desempenho de Algoritmos de Ordenação')
plt.grid(True)

plt.show()
