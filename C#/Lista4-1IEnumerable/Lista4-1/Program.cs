using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Lista4_1
{
interface IStream
{
    bool eos();
    void reset();
}

public class List_el<T> 
{
    public List_el(T data)
    {
        Data = data;
    }
    public T Data { get; set; }
    public List_el<T> Next { get; set; }
    }

class ILEnum<T> : IEnumerator<T>
{
    List_el<T> start;
    List_el<T> curr;
    public ILEnum(List_el<T> List) {
        this.start=List;
    }
    public bool MoveNext()
    {
        if (this.curr == null)
            this.curr = this.start;
        else
            this.curr = this.curr.Next;
        return this.curr != null;
    }
    object IEnumerator.Current { get { return Current; } }
    void IDisposable.Dispose() {}
    public T Current { get { return curr.Data; } }
    public void Reset()
    {
        this.curr = this.start;
    }
}

public class List<T> : IEnumerable<T>
{
    List_el<T> start = null;
    List_el<T> end = null;
    int Length { get; set; }
    public void Add_to_end(T data)
    {
        List_el<T> new_el = new List_el<T>(data);
        if (start == null)
            start = new_el;
        else
            end.Next = new_el;
        end = new_el;
        Length++;
    }
    public void Add_to_start(T data)
    {
        List_el<T> new_el = new List_el<T>(data);
        new_el.Next = start;
        start = new_el;
        if (Length == 0)
            end = start;
        Length++;
    }
    public T Delete_from_start()
    {
        if (start == null)
            return default(T);
        Length--;
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

    public bool Empty { get { return Length == 0; } }
    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
    public IEnumerator<T> GetEnumerator()
    {
        return new ILEnum<T>(start);
    }

    public override string ToString()
    {
            return String.Format("Lista o dlugosci: "+Convert.ToString(this.Length));
    }
    public T this[int indeks]
    {
        get
        {
            List_el<T> current = start;
                while (current != null)
                {
                    if (indeks == 0)
                        return current.Data;
                    current = current.Next;
                    indeks -= 1;
                }
                return default(T);
        }
    }
}

class IntStream : IStream
{
    static int num = -1;

    public int next()
    {
        IntStream.num++;
        return IntStream.num;
    }

    public bool eos()
    {
        if (IntStream.num + 1 <= 2147483647)
            return false;
        else
            return true;
    }
    public void reset()
    {
        IntStream.num = -1;
    }
}

class PrimeStream : IntStream,IStream
{
    static int num = -1;

    private bool Prime(long n)
    {
        for (int i = 2; i <= n / 2 + 1; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    public int next()
    {
        do
            PrimeStream.num++;
        while (!Prime(PrimeStream.num));
        return PrimeStream.num;
    }

    public bool eos()
    {
        long cur_p = PrimeStream.num;
        do
            cur_p++;
        while (!Prime(cur_p));
        if (cur_p <= 2147483647)
            return false;
        else
            return true;
    }

}

class RandomStream : IntStream, IStream
{
    public int next(int from, int to)
    {
        Random x = new Random();
        return x.Next(from, to);
    }

    public bool eos()
    {
        return false;
    }


}

class RandomWordStream : IStream
{
    private PrimeStream ps = new PrimeStream();
    private RandomStream rs = new RandomStream();

    public string Next()
    {
        string s = "";
        int lng = ps.next();
        char rnd;
        for (int i = 0; i < lng; i++)
        {
            rnd = Convert.ToChar(rs.next(65, 122));
            s += Convert.ToString(rnd);
        }
        return s;
    }

    public bool eos()
    {
        if (ps.eos())
            return true;
        return false;

    }

    public void reset()
    {
        ps.reset();
    }

}

    class Program
    {
        static void Main(string[] args)
        {
            List<string> L = new List<string>();
            L.Add_to_start("asdd");
            L.Add_to_end("fsgsd");
            foreach (string elem in L)
                Console.WriteLine(elem);
            Console.WriteLine();
            for (int i=0;i<2; i++)
               Console.WriteLine(L[i]);
            Console.WriteLine(L);
            Console.Read();
        }
    }
}
