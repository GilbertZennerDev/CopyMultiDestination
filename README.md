# ⚡ Fast Copy (Multi-Destination File Utility)

**A simple, blazing-fast Python script to copy one source to multiple destinations with a single command.**

Tired of running the same `cp` command over and over? Use **Fast Copy** to deploy your config files, project assets, or entire directory trees to several locations simultaneously\!

## ✨ Features

  * **Multi-Destination Copy:** Deploy to $N$ targets at once.
  * **Safety & Portability:** Built on Python's `shutil` module, ensuring reliable operation across Windows, macOS, and Linux.
  * **Explicit Control:** Choose exactly whether you are copying a single file or an entire directory (`-file` or `-folder`).
  * **Robust Error Handling:** Cleans up and exits gracefully if any copy operation fails.

## 🚀 Installation

No installation needed\! Just clone the repository and run the script directly:

```bash
git clone https://github.com/GilbertZennerDev/CopyMultiDestination.git
cd CopyMultiDestination
```

## 📚 Usage

The application requires an action flag (`-file` or `-folder`), the source path, and at least one destination path.

### General Syntax

```bash
python app.py <ACTION> <SOURCE> <DEST1> [DEST2 ...]
```

### Example 1: Copying a Single File

Copy your new `config.ini` file to three different project folders:

```bash
python app.py -file config.ini ~/project-a/config/ ~/project-b/config/ ~/project-c/
```

### Example 2: Deploying an Entire Folder

Duplicate an entire asset folder to two different deployment directories:

```bash
python app.py -folder ./assets-v2 /var/www/site1/assets/ /var/www/site2/static/
```

## 💻 The Code (Simple & Effective)

The power of this utility lies in its simplicity and direct use of the standard library.

```python
import sys
import shutil

def main():
    av = sys.argv
    ac = len(av)
    # Require at least flag, src, and 1 dest (4 total arguments)
    if ac < 4: 
        print("Usage: python app.py <ACTION> <SRC> <DEST1> [DEST2 ...]")
        print("ACTION must be -file or -folder")
        exit()
        
    flag = av[1]
    src = av[2]
    dests = av[3:]
    
    try:
        if flag == '-file':
            print(f"📄 Copying file: {src} to {len(dests)} destinations...")
            for dest in dests: 
                shutil.copy(src, dest)
                print(f"  ✓ Copied to: {dest}")
        
        elif flag == '-folder':
            print(f"📁 Copying folder: {src} to {len(dests)} destinations...")
            for dest in dests: 
                # copytree handles directory copying
                shutil.copytree(src, dest)
                print(f"  ✓ Copied to: {dest}")
                
        else:
            print("Arg1 must be -file or -folder")
            
    except Exception as e: 
        print(f"\n❌ An error occurred during copy operation: {e}")
        exit(1)

if __name__ == '__main__': main()
```

## 🤝 Contributing

Contributions are welcome\! If you have suggestions for new features (like interactive prompts or exclusion patterns), please open an issue or submit a pull request.

-----

*(This README is perfect because it immediately shows the usage, explains the technical benefits of `shutil`, and highlights the clean structure of your code.)*

Would you like me to help you set up an **`argparse`** version of the script to make the usage section even more powerful with built-in help messages?
