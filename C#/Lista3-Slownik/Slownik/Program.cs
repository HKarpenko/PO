using System;

namespace Slownik
{
    public class Dict_el<K, V>
    {
        public Dict_el(K klucz, V wart)
        {
            this.Klucz = klucz;
            this.Wart = wart;
        }
        public K Klucz;
        public V Wart;
        public Dict_el<K, V> Next;
    }

    public class Dict<K, V>
    {
        Dict_el<K, V> d_start = null;
        Dict_el<K, V> d_end = null;
        public void Add_to_dict(K klucz, V wart)
        {
            bool E = false;
            Dict_el<K, V> new_komb = new Dict_el<K, V>(klucz, wart);
            if (d_start == null)
            {
                d_end = new_komb;
                d_start = new_komb;
            }
            else
            {
                Dict_el<K, V> curr = d_start;
                while (curr != null)
                {
                    if (curr.Klucz.Equals(klucz))
                    {
                        curr.Wart = wart;
                        E = true;
                        return;
                    }
                    curr = curr.Next;
                    
                }
                    d_end.Next = new_komb;
                    d_end = new_komb;
            }
        }
            

        public void Delete_from_dict(K klucz)
        {
            if (d_start != null)
            {
                if (d_start.Next == null)
                    d_start = d_end = null;
                Dict_el<K, V> curr = d_start;
                Dict_el<K, V> prev = null;
                while (curr != null)
                {
                    if (curr.Klucz.Equals(klucz))
                    {
                        if (prev != null)
                        {  //ostatni lub w srodku
                            prev.Next = curr.Next;
                            if (curr.Next == null)
                                d_end = prev;
                        }
                        else
                        {               //pierwszy el
                            d_start = d_start.Next;
                        }
                    }
                    prev = curr;
                    curr = curr.Next;
                }
            }
        }
        public V Value_dict(K klucz)
        {
            if (d_start == null)
                return default(V);
            else
            {
                Dict_el<K, V> curr = d_start;
                while (curr != null)
                {
                    if (curr.Klucz.Equals(klucz))
                        return curr.Wart;
                    curr = curr.Next;
                }
                return default(V);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Dict<string, int> D = new Dict<string, int>();
            D.Add_to_dict("a", 1);
            D.Add_to_dict("b", 2);
            System.Console.WriteLine("a - " + D.Value_dict("a"));
            System.Console.WriteLine("b - " + D.Value_dict("b"));
            D.Add_to_dict("b", 3);
            System.Console.WriteLine("b - "+D.Value_dict("b"));
            D.Delete_from_dict("a");
            System.Console.WriteLine("a - " + D.Value_dict("a"));
            Console.Read();
        }
    }
}