# Console Hex Viewer

[English](#english) | [Русский](#русский)

<a id="english"></a>
## English

A small C++ console utility for inspecting binary files in hexadecimal and ASCII form. The current implementation is a **read-only viewer**: it can open a file and navigate to an offset, but it does not edit or save bytes.

### Features

- Open a file in binary mode (`open`).
- Display file data as hexadecimal byte values and printable ASCII characters.
- Show data in rows of 16 bytes, including the byte offset.
- Jump to a specified offset (`goto`), including hexadecimal offsets such as `0x100`.
- Close the current file (`close`) or exit the application (`exit`).

### Technology

- C++20
- Standard C++ file streams (`std::ifstream`)
- Console input parsing with `std::stringstream`

### Requirements

- Windows and a compatible Visual Studio C++ toolset
- C++20 support

### Build and run

1. Clone or download this repository.
2. Open `Console_hex.slnx` in a compatible version of Visual Studio.
3. Select a configuration such as **Debug | x64**.
4. Build the solution and run the console application.

The build has not been independently verified as part of this README preparation.

### Commands

| Command | Example | Description |
|---|---|---|
| `open` | `open test.bin` | Open a file in binary mode and display the first five rows. |
| `goto` | `goto 0x100` | Display five rows starting at the specified offset. Decimal offsets are also accepted by the numeric conversion used in the code. |
| `close` | `close` | Close the open file, if any. |
| `exit` | `exit` | Exit the application. |

Each row displays an offset, hexadecimal byte values, and an ASCII column. Bytes outside the printable ASCII range are shown as dots.

### Current limitations

- Despite the repository name, the current code does not provide byte editing or saving changes; it is a viewer.
- The command parser reads whitespace-separated tokens, so file paths containing spaces are not reliably supported.
- Invalid or out-of-range values supplied to `goto` can cause a conversion exception; input validation should be improved.
- The current implementation displays a fixed number of rows per command and does not yet provide a search function.
- Use copies of important files when experimenting with binary-file tools.

### Project structure

```text
Console_hex/
├── Console_hex.cpp
└── Console_hex.vcxproj
```

### Purpose

This project is a learning exercise in binary file streams, offsets, hexadecimal formatting, ASCII display, and console command handling.

---

<a id="русский"></a>
## Русский

Небольшая консольная утилита на C++ для просмотра бинарных файлов в шестнадцатеричном и ASCII-представлении. Текущая реализация — **просмотрщик без редактирования**: файл можно открыть и перейти к смещению, но изменять и сохранять байты программа пока не умеет.

### Возможности

- Открытие файла в бинарном режиме (`open`).
- Вывод данных в виде шестнадцатеричных значений байтов и печатных ASCII-символов.
- Отображение строк по 16 байтов со смещением.
- Переход к заданному смещению (`goto`), в том числе к шестнадцатеричным смещениям, например `0x100`.
- Закрытие файла (`close`) и выход (`exit`).

### Технологии

- C++20
- Файловые потоки C++ (`std::ifstream`)
- Разбор консольного ввода через `std::stringstream`

### Требования

- Windows и совместимый toolset C++ для Visual Studio
- Поддержка C++20

### Сборка и запуск

1. Клонируйте репозиторий или скачайте архив.
2. Откройте `Console_hex.slnx` в совместимой версии Visual Studio.
3. Выберите конфигурацию, например **Debug | x64**.
4. Соберите решение и запустите консольное приложение.

Сборка не проверялась отдельно в рамках подготовки этого README.

### Команды

| Команда | Пример | Описание |
|---|---|---|
| `open` | `open test.bin` | Открыть файл в бинарном режиме и показать первые пять строк. |
| `goto` | `goto 0x100` | Показать пять строк, начиная с указанного смещения. Также допускаются десятичные смещения. |
| `close` | `close` | Закрыть открытый файл, если он есть. |
| `exit` | `exit` | Завершить работу приложения. |

Каждая строка содержит смещение, значения байтов в HEX и ASCII-колонку. Байты вне диапазона печатных ASCII-символов отображаются точками.

### Текущие ограничения

- Несмотря на название репозитория, текущий код не умеет редактировать байты или сохранять изменения — это просмотрщик.
- Парсер разделяет ввод по пробелам, поэтому пути с пробелами надёжно не поддерживаются.
- Некорректное или слишком большое значение в `goto` может вызвать исключение при преобразовании; проверку ввода нужно улучшить.
- Команда показывает фиксированное число строк; функции поиска пока нет.
- Для экспериментов с бинарными файлами используйте копии важных данных.

### Структура проекта

```text
Console_hex/
├── Console_hex.cpp
└── Console_hex.vcxproj
```

### Цель проекта

Практика работы с бинарными файловыми потоками, смещениями, HEX-форматированием, ASCII-отображением и обработкой консольных команд.
