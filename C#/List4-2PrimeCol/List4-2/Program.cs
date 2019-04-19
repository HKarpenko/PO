using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace List4_2
{
    class IPrimeEnum : PrimeCollection, IEnumerator<int>
    {
        int curr;
        public IPrimeEnum(int one)
        {
            this.curr = one;
        }
        public bool MoveNext()
        {
            do
                curr++;
            while (!Prime(curr) && (curr != 2147483647));
            if (curr == 2147483647)
                return false;
            return true;
        }
        object IEnumerator.Current { get { return Current; } }
        void IDisposable.Dispose() { }
        public int Current { get { return this.curr; } }
        public void Reset()
        {
            this.curr = 1;
        }
    }
    class PrimeCollection : IEnumerable<int>
    {
        int current;
        protected bool Prime(long n)
        {
            for (int i = 2; i <= n / 2 + 1; i++)
                if (n % i == 0)
                    return false;
            return true;
        }
        public PrimeCollection()
        {
            current = 1;
        }
        public int Next() {
            do
                current++;
            while (!Prime(current)&&(current!= 2147483647));
            if (current == 2147483647)
                return default(int);
            return current;
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
        public IEnumerator<int> GetEnumerator()
        {
            return new IPrimeEnum(1);
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            PrimeCollection primes = new PrimeCollection();
            foreach (int elem in primes)
                Console.WriteLine(elem);
            Console.Read();
        }
    }
}
