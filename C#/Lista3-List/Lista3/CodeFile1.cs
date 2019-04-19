using System;

namespace First
{
    public class List_el<T>
    {
        public List_el(T data)
        {
            Data = data;
        }
        public T Data { get; set; }
        public List_el<T> Next { get; set; }
    }

    public class List<T>
    {
        List_el<T> start=null;
        List_el<T> end=null;
        int len=0;
        public void Add_to_end(T data)
        {
            List_el<T> new_el = new List_el<T>(data);
            if (start == null)
                start = new_el;
            else
                end.Next = new_el;
            end = new_el;
            len++;
        }
        public void Add_to_start(T data)
        {
            List_el<T> new_el = new List_el<T>(data);
            new_el.Next = start;
            start = new_el;
            if (len == 0)
                end = start;
            len++;
        }
        public T Delete_from_start()
        {
            if (start == null)
                return default(T);
			len--;
            T ret = start.Data;
            start = start.Next;
            return ret;
        }
        public T Delete_from_end()
        {
            if (start == null)
                return default(T);
			len--;
            T ret = end.Data;
            if (start.Next == null)
            {
                start = null;
                end = null;
                return ret;
            }
            List_el<T> current = start;
            while ((current.Next).Next != null)
                current = current.Next;
            current.Next = null;
            end = current;
            return ret;
        }

        public bool Empty { get { return len == 0; } }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<string> L = new List<string>();
            System.Console.WriteLine("Stworzylismy liste, czy jest ona pusta? " + L.Empty);
            L.Add_to_start("asdd");
            System.Console.WriteLine("Czy teraz lista pusta? "+L.Empty);
            L.Add_to_end("fsgsd");
            System.Console.WriteLine(L.Delete_from_start());
            System.Console.WriteLine(L.Delete_from_end());
            System.Console.WriteLine("Dodalismy i usunielismy 2 elementy. Lista pusta? " + L.Empty);
            System.Console.WriteLine("Probujemy usunac element, ktorego nie ma: "+L.Delete_from_end());
            Console.Read();
        }
    }
}