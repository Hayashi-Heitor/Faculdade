import pandas as pd

df = pd.read_csv(r"jogoscorretoUTF8.csv")
vpf=df.groupby('Fabricante') ['Venda_Global'].sum()
fmv = vpf.idxmax()
maior_venda = vpf.max()
print(f'Fabricante com a maior venda global: {fmv}')
print(f'Venda Global Total: {maior_venda} milhões de dólares')
