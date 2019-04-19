using System.Threading;
using System;

namespace First
{
    class IntStream
    {
        static int num = -1;

        public int next()
        {
            IntStream.num++;
            return IntStream.num;
        }

        public bool eos()
        {
            if (IntStream.num+1 <= 2147483647)
                return false;
            else
                return true;
        }
        public void reset()
        {
            IntStream.num = -1;
        }
    }

    class PrimeStream : IntStream
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

    class RandomStream : IntStream
    {
        public int next(int from, int to)
        {
            Random x = new Random();
            Thread.Sleep(15);
            return x.Next(from,to);
        }

        public bool eos()
        {
            return false;
        }


    }

    class RandomWordStream
    {
        private PrimeStream ps = new PrimeStream();
        private RandomStream rs = new RandomStream();

        public string next()
        {
            string s="";
            int lng = ps.next();
            char rnd;
            for(int i=0;i<lng;i++)
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
            RandomWordStream rws = new RandomWordStream();
            for (int i = 0; i < 10; i++)
                Console.WriteLine(rws.next());
            Console.Read();
        }
    }
}
