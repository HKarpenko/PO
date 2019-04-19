package javaapplication1;

public class Przypisz extends Wyrazenie{
        Zmienna zmien;
        Wyrazenie wyraz;
        public Przypisz(Zmienna z, Wyrazenie wyr){
            zmien=z;
            wyraz=wyr;
        }
        public double oblicz(){
            Zmienna.wloz(zmien.name,wyraz.oblicz());
            return Zmienna.Zmienne.get(zmien.name);
        }
        public String toString(){
            return "("+zmien.toString()+"="+wyraz.toString()+")";
        }
    } 