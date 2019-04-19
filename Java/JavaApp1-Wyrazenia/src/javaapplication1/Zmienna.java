package javaapplication1;

import java.util.HashMap;
import java.util.Map;

public class Zmienna extends Wyrazenie{
        static Map<String,Double> Zmienne = new HashMap<>();
        String name;
        public Zmienna(String name){
            this.name=name;
        }
        public Zmienna(String name, double wartosc){
            this.name=name;
            Zmienne.put(name, wartosc);
        }
        public static void wloz(String name,double wartosc){
            Zmienne.put(name, wartosc);
        }
        public double oblicz(){
            return Zmienne.get(name);
        }
        public String toString(){
            return name;
    }
    }
