# Practical 06: Runtime Polymorphism and Abstract Classes

- **Student Name:** Satinderpal Singh Chaney
- **Roll Number:** E26B00S2034

## Aim
To demonstrate how a base-class interface can be used to call the correct derived-class function at runtime.

## Question
Create an abstract `Shape` class and implement `Circle`, `Rectangle`, and `Triangle` with an `area()` function.

## Virtual Functions, Abstract Classes & Runtime Polymorphism
- **Abstract Class (`Shape`):** A class containing at least one pure virtual function (`virtual double area() const = 0;`) is abstract. `Shape` cannot be instantiated directly (`Shape s;` fails at compile time) because it serves strictly as an interface without a complete concrete implementation.
- **Virtual Functions & Dynamic Dispatch:** Marking `area()` and `display()` as `virtual` in `Shape` and overriding them with `override` in `Circle`, `Rectangle`, and `Triangle` enables C++ to resolve function calls at runtime using the object's vtable (virtual method table) rather than the static pointer type (`Shape*`).
- **Virtual Destructor:** Declaring `virtual ~Shape() = default;` guarantees that deleting a derived object through a `Shape*` base pointer invokes the derived class destructor first, preventing resource leaks.

## Compilation & Execution

### Windows (PowerShell / MinGW `g++`)
```powershell
g++ -std=c++17 -Wall -Wextra practical6.cpp -o practical6.exe
.\practical6.exe
```

### Linux / macOS (`g++` / `clang++`)
```bash
g++ -std=c++17 -Wall -Wextra practical6.cpp -o practical6
./practical6
```

## Memory-Checking Instructions

### Option 1: AddressSanitizer & UndefinedBehaviorSanitizer (GCC / Clang — Linux, macOS, WSL)
```bash
g++ -std=c++17 -g -O1 -fsanitize=address,undefined practical6.cpp -o practical6_asan
./practical6_asan
```

### Option 2: Valgrind (Linux / WSL)
```bash
g++ -std=c++17 -g practical6.cpp -o practical6_dbg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./practical6_dbg
```
Expected summary: `All heap blocks were freed -- no leaks are possible` and `0 errors from 0 contexts`.

## Uploading to GitHub
1. Create a new repository on GitHub (for example, `practical-06-runtime-polymorphism` or `practical 6`).
2. Extract the ZIP archive into a local folder and push:
   ```bash
   git init
   git add .
   git commit -m "Add Practical 06: Runtime Polymorphism and Abstract Classes"
   git branch -M main
   git remote add origin <YOUR_GITHUB_REPOSITORY_URL>
   git push -u origin main
   ```
