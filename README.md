# algorithms

<details>
  <summary>Оглавление</summary>

- [Протестировать структуру "std::map"](#протестировать-структуру-stdmap)
- [Две программы и один Makefile](#две-программы-и-один-makefile)
- [Класс NDArray](#класс-ndarray)
- [Сериализация дерева](#сериализация-дерева)
- [Кластеризация географических объектов](#кластеризация-географических-объектов)
- [Поиск дубликатов](#поиск-дубликатов)
- [Парсинг wav файла](#парсинг-wav-файла)

</details>

## [Протестировать структуру "std::map"](https://github.com/fedmog1lnkv/algorithms/tree/main/map_task)

Необходимо написать код (`C++` и `Python`) и протестировать структуры `std::map`(`C++`) и `dict`(`Python`) на предмет скорости заполнения и требования к памяти.

- Код должен содержать `Makefile`

- В `Makefile` должен быть этап `run` для сборки, запуска и построения графиков

- Должен выводится график зависимости скорости выполнения в миллисекундах (микросекундах или наносекундах, подобрать наиболее подходящий порядок величины) от количества элементов

- Должен выводится график зависимости требуемого объема памяти в байтах(килобайтах или мегабайтах, подобрать наиболее подходящий порядок величины) от количества элементов

- Количество элементов `от 1 до 10**7` включительно для `С++` и `от 1 до 10 ** 5` для `Python`

- Тип ключа и элементов `int`

---

## [Две программы и один Makefile](https://github.com/fedmog1lnkv/algorithms/tree/main/2prog_1make)

Написать две программы и автоматизировать их
сборку и запуск

- Первая программа: Генерирует `n` (передается через командную
  строку, первый параметр) наборов углов `от -M_PI
до М_PI`. Каждый набор состоит из трех значений.
  Сохраняет каждый набор в файл, каждый набор
  в новой строке, имя которого задается вторым
  параметром командной строки.
- Вторая программа: Читает сгенерированный файл и выдает углы в
  градусах для каждого набора согласно формуле:
  $angle = 2*sin(x)*sin(y) + cos(z)$

---

## [Класс NDArray](https://github.com/fedmog1lnkv/algorithms/tree/main/NDArray)

Реализовать класс `NDArray` на языке `C++` для представления многомерных массивов(типы данных `int`, `float`).

Должны быть реализованы методы:

- Создание пустого массива заданного размера

- Создание массива заполненного нулями

- Создание массива заполненного единицами

- Создание массива заполненного случайными значениям

- Операторы поэлементного сложения, вычитания, умножения, деления

- Матричное умножение

- Метод для транспонирования

- Операции сокращения: минимум, максимум, среднее для определенной размерности

---

## [Сериализация дерева](https://github.com/fedmog1lnkv/algorithms/tree/main/serialization_task)

Добавить методы для сериализации/десериалиации дерева.

Начальный код:
  
``` python

from enum import Enum

class Alignment(Enum):
    HORIZONTAL = 1
    VERTICAL = 2

class Widget():

    def __init__(self, parent):
        self.parent = parent
        self.childrens = []
        if self.parent is not None:
            self.parent.add_children(self)

    def add_children(self, children: "Widget"):
        self.childrens.append(children)

    def to_binary(self):
        return b"0"

    @classmethod
    def from_binary(self, data):
        pass

    def __str__(self):
        return f"{self.__class__.__name__}{self.childrens}"

    def __repr__(self):
        return str(self)

class MainWindow(Widget):

    def __init__(self, title: str):
        super().__init__(None)
        self.title = title

class Layout(Widget):

    def __init__(self, parent, alignment: Alignment):
        super().__init__(parent)
        self.alignment = alignment

class LineEdit(Widget):

    def __init__(self, parent, max_length: int=10):
        super().__init__(parent)
        self.max_length = max_length

class ComboBox(Widget):

    def __init__(self, parent, items):
        super().__init__(parent)
        self.items = items

app = MainWindow("Application")
layout1 = Layout(app, Alignment.HORIZONTAL)
layout2 = Layout(app, Alignment.VERTICAL)

edit1 = LineEdit(layout1, 20)
edit2 = LineEdit(layout1, 30)

box1 = ComboBox(layout2, [1, 2, 3, 4])
box2 = ComboBox(layout2, ["a", "b", "c"])

print(app)

bts = app.to_binary()
print(f"Binary data length {len(bts)}")

new_app = MainWindow.from_binary(bts)
print(new_app)
```

---

## [Кластеризация географических объектов](https://github.com/fedmog1lnkv/algorithms/tree/main/cluster_task)

При помощи `spanning tree` разбить граф на 40 кластеров.

---

## [Поиск дубликатов](https://github.com/fedmog1lnkv/algorithms/tree/main/hash_task)

Написать функцию для поиска дубликатов среди списка файлов. Функция одним из параметров должна принимать функцию хеширования.

`def find_duplicates(files: list[str], hash_function: callable) -> list[str]:`

Реализовать следующие hash функции:

- CRC

```
highorder = h & 0xf8000000
h = h << 5
h = h ^ (highorder >> 27)
h = h ^ ki
```

- PJW

```
h = (h << 4) + ki
g = h & 0xf0000000
if (g != 0)
    h = h ^ (g >> 24)
    h = h ^ g
```

- BUZ

```
highorder = h & 0x80000000
h = h << 1
h = h ^ (highorder >> 31)
h = h ^ R[ki]
```

, где `ki` - входная последовательность символов, `R` - функция, которая для `ki` символа, дает случайное число.

На выходе количество дубликатов и время работы для каждой `hash` функции. В выходной результат добавить результат для работы встроенной функции `hash`.

## [Парсинг wav файла](https://github.com/fedmog1lnkv/algorithms/tree/main/wav_task)

Разобрать `wav` файл. Получить два массива для двух каналов. Вывести на экран в виде графика.
