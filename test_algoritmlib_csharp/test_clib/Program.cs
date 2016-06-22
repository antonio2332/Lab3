using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace test_clib
{
    class Program
    {
        [DllImport("algorithm_lib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int findLastIndex(Int32[] arr, Int32 size_arr);

        [DllImport("algorithm_lib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr array_from_file(string file_name, out Int32 arr_size);

        static void Main(string[] args)
        {
           
                Int32[] array;
                char k;
                while (true)
                {
                     try
                    {
                            Console.Clear();
                            Console.WriteLine("\nВычисление индекса последнего уникального значения.\nВыберите способ ввода данных");
                            Console.WriteLine("1. Ручной ввод в консоли");
                            Console.WriteLine("2. Получить из файла");
                            Console.WriteLine("3. Выход");

                            k = Console.ReadKey().KeyChar;

                            if (k == '1')
                            {
                                array = getArrayFromCmdInput();
                            }
                            else if (k == '2')
                            {
                                array = getArrayFromFile();
                            }
                            else
                            {
                                return;
                            }


                            Int32 lastIndex = findLastIndex(array, (Int32)array.Length);
                            Console.WriteLine("Последний индекс: {0}", lastIndex);
                            Console.ReadLine();
                    }
                     catch (Exception ex)
                     {
                         Console.WriteLine("Error: {0}", ex.Message);
                         Console.ReadLine();
                     }
            }
            
        }

        private static Int32[] getArrayFromFile()
        {
            try
            {
                Console.Clear();
                Console.WriteLine("Введите путь к файлу");
                string filePath = Console.ReadLine();

                Int32 arraySize;
                IntPtr arrPtr = array_from_file(filePath, out arraySize);
                Int32[] array = new Int32[arraySize];

                Marshal.Copy(arrPtr, array, 0, arraySize);
                return array;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Произошла ошибка,\n {0}", ex.Message);
                Console.ReadLine();
                return null;
            }
        }

        private static Int32[] getArrayFromCmdInput()
        {
            try {
                Int32[] array;
                Console.Clear();
                Console.WriteLine("Ручной ввод значений массива данных");
                Console.WriteLine("Введите количество аргументов:");
                int N = int.Parse(Console.ReadLine());

                if (N < 1 || N > 100000)
                    throw new ArgumentOutOfRangeException("Длина массива должна быть от 1 до 100000!");

                array = new Int32[N];
                int i = 0;

                while (i < N)
                {
                    Console.WriteLine("Введите {0}-е значение: ", i + 1);
                    array[i++] = Int32.Parse(Console.ReadLine());
                }
                return array;

            }catch(Exception ex){
                Console.WriteLine("Произошла ошибка,\n {0}", ex.Message);
                return null;
            }
        }
    }
}
