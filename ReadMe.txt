UK
Create a Computer class with the following properties: CPU frequency (MHz), number of cores, memory capacity (MB), hard disk capacity (GB).

Define two virtual methods: "Cost", which returns the approximate estimated cost of the computer,
calculated by the formula Processor frequency * number of cores / 100 + memory capacity / 80 + hard disk capacity / 20
and a logical "Suitability" method that returns true if the processor frequency is at least 2000 MHz, the number of cores is at least 2,
memory capacity of at least 2048 MB, and hard disk capacity of at least 320 GB.

Also define the "Information" method, which returns a string containing information about the computer:
CPU frequency, number of cores, memory capacity, hard disk capacity, cost and suitability for our needs.

Also create a descendant class Notebook, with the additional property Battery life (in minutes)
and redefine the methods: the method "Cost" returns a number equal to the cost of a conventional computer + the number of minutes of battery life / 10,
and the "Fitness" method returns the truth, when the laptop is suitable as a normal computer, and the battery life is at least 60 minutes.
In the main program, create a regular computer and laptop and display information about them.



UA
Створити клас Комп'ютер з властивостями: Частота процесора (МГц), кількість ядер, об'єм пам'яті (МБ), об'єм жорсткого диска (ГБ).

Визначити два віртуальні методи: "Вартість", що повертає приблизну розрахункову вартість комп'ютера, 
що розраховується за формулою Частота процесора * кількість ядер / 100 + об'єм пам'яті / 80 + об'єм жорсткого диска / 20 
і логічний метод "Придатність", що повертає істину (true), якщо частота процесора щонайменше 2000 МГц, кількість ядер щонайменше 2, 
об'єм пам'яті щонайменше 2048 МБ, і об'єм жорсткого диска щонайменше 320 Гб. 

Визначити також метод «Інформація», який повертає рядок, що містить інформацію про комп'ютер: 
частоту процесора, кількість ядер, об'єм пам'яті, об'єм жорсткого диска, вартість та придатність для наших потреб.

Створити також клас нащадок Ноутбук, з додатковою властивістю Тривалість автономної роботи (у хвилинах) 
і перевизначити методи: метод «Вартість» повертає число, що дорівнює вартості звичайного комп'ютера + кількість хвилин автономної роботи / 10, 
а метод «Придатність» повертає істину, тоді коли і ноутбук придатний як звичайний комп'ютер, і тривалість автономної роботи не менше 60 хвилин.
У головній програмі створити звичайний комп'ютер та ноутбук та вивести інформацію про них.

