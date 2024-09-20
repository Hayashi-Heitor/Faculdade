import pandas as pd

df = pd.read_csv(r"jogoscorretoUTF8.csv")
df.columns=df.columns.str.strip()
cve = 'Vendas_Europa'

if cve in df.columns:
  jme=df.loc[df[cve].idxmax()]
  print(f"Jogo mais vendido na Europa: {jme['Nome']}")
  print(f"Vendas na Europa: {jme[cve]} milhões")

else:
  print(f"A coluna '{cve}' não foi encontrada. Verifique os nomes das colunas.")
