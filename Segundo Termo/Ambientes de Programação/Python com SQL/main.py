import sqlite3

con = sqlite3.connect("BD_Pets.db")
cursor = con.cursor()

sql_Reptil = "INSERT INTO Especie (esp_descricao) VALUES ('Réptil')"
sql_Pitucha = "INSERT INTO Animais (Ani_nome,Ani_cor,Ani_especie) VALUES ('Pitucha', 'Preto', 3)"
sql_Delete = "DELETE FROM Animais WHERE Ani_nome = 'Cristal'"
sql_Update = "UPDATE Animais SET Ani_nome = 'Verde' WHERE Ani_nome = 'Pipoca'"
sql_Like = "UPDATE Animais SET Ani_Nome = 'Verde' WHERE Ani_Nome LIKE '%P%'"
cursor.execute(sql_Like)
con.commit() #Efetivar o banco

print("----------------Lista de Animais----------------")
sql = "SELECT * FROM Animais"
cursor.execute(sql)
dados = cursor.fetchall()
for animal in dados:
    print(animal)
