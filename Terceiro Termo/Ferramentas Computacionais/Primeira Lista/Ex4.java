public class Main {

    public static void main(String[] args) {

        int Minutos, Segundos = 5000, Horas;

        Minutos = Segundos / 60;
        Segundos = Segundos % Minutos;
        Horas = Minutos / 60;
        Minutos = Minutos % Horas;

        System.out.println(Horas + " : " + Minutos + " : " + Segundos);
    }

}
