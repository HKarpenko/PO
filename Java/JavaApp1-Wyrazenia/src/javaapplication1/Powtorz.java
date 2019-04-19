package javaapplication1;

public class Powtorz extends Wyrazenie{
        int command;
        Integer licznik;
        Wyrazenie[] for_wyr;
        public Powtorz(Wyrazenie ile, Wyrazenie[] wyr){
            command=wyr.length;
            licznik=(int)Math.floor(ile.oblicz());
            for_wyr = new Wyrazenie[wyr.length];
            for_wyr=wyr;
        }
        public double oblicz(){
            if(licznik==0)
                return 0.0;
            for(int i=0;i<licznik-1;i++)
                for(int j=0;j<command;j++)
                    for_wyr[j].oblicz();
            for(int i=0;i<command-1;i++)
                    for_wyr[i].oblicz();
            return for_wyr[command-1].oblicz();
        }
        public String toString(){
            String wyn="for("+licznik.toString()+") : \n";
            for(int i=0;i<command;i++)
                wyn+="\t"+for_wyr[i].toString()+"\n";
            return wyn;
        }
    } 