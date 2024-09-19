import pandas as pd

df = pd.read_csv("jogoscorretoUTF8.csv")
j25m = df[df['Venda_Global'] > 25]
print(j25m)
