import pandas as pd

df = pd.read_csv(r"jogoscorretoUTF8.csv")
qja=df['Ano'].value_counts().sort_index() 
print("Quantidade de jogos lançados por ano:")
print(qja)

a_ma = qja.idxmax()
q_a_ma = qja.max()
print(f'\nAno com o maior número de lançamentos: {a_ma} com {q_a_ma} jogos')

df_a_ma = df[df ['Ano'] == a_ma]
g_pr = df_a_ma['Genero'].value_counts().idxmax()
q_g_pr=df_a_ma['Genero'].value_counts().max()
print(f'\nNo ano de {a_ma}, a maioria dos jogos era do gênero: {g_pr} com {q_g_pr} jogos.')
