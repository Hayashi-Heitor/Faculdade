
#calcula a média
def media(x, y):
    m=(x + y) / 2
    return m

med = media(2, 4)
print(f"A média é: {med}")
print(f"A função: {media.__name__} é: {media.__doc__}")
help(media)

#exemplo de função com predefinição
def retangulo(x1=0, y1=0, x2=10, y2=10):
    print(x1, y1, x2, y2)

retangulo()
retangulo(1, 1)
retangulo(x2=100)
print("\n")

def seila(teste, *valores):
    print(f"---{teste}---")
    for param in valores:
        print(param)

seila('Testando vários parâmetros', 'Cris', 'Carol', 'Chico')

def exibe(lista, titulo):
    lista.sort()
    print("-------------------")
    print(' ', titulo, ' ')
    print("-------------------")
    for nome in lista:
        print(nome)

l_alunos=[]
l_alunos.append("Chris")
l_alunos.append("Gi")
l_alunos.append("Douglas")

l_prof=[]
l_prof.append("Carol")
l_prof.append("Francisco")
l_prof.append("Mario")

print("\n")
exibe(l_alunos, "Alunos queridos")
print("\n")
exibe(l_prof, "Professores queridos")
