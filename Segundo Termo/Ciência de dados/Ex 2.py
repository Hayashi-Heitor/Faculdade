import pandas as pd

df = pd.read_csv("jogoscorretoUTF8.csv")
iRf = df ['Fabricante'].value_counts()
print(iRf)
