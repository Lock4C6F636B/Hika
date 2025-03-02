# HiKa - Japanese Learning Application

![HiKa Logo](path/to/logo.png)

## Overview

HiKa is a comprehensive Japanese language learning application designed to help users practice and master various aspects of the Japanese language. The application consists of four main modules:

1. **Alphabet** - Practice writing hiragana and katakana characters
2. **Word Bringer** - Memorize Japanese vocabulary through interactive exercises
3. **Inflection Master** - Practice verb and adjective conjugations
4. **Sentencer** - Translate sentences between English and Japanese

## Features

- **Multiple difficulty levels** ranging from romanized Japanese to full Japanese with kanji
- **Customizable learning experience** with the ability to focus on specific lessons
- **Progress tracking** with a streak counter for consistent practice
- **Visual feedback** system with encouraging messages for correct answers
- **Comprehensive vocabulary database** organized by categories and lessons

## Screenshots

![Main Menu](path/to/screenshot1.png)
![Word Bringer Module](path/to/screenshot2.png)
![Alphabet Practice](path/to/screenshot3.png)

## Installation

### Prerequisites
- Qt 6.0 or higher
- C++23 compatible compiler
- CMake 3.16 or higher

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/HiKa.git
cd HiKa

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Run the application
./HiKa
```

## Usage

1. **Launch the application** by running the executable
2. **Select a module** from the main menu
3. **Choose difficulty level** based on your proficiency
4. **Select specific lessons** to focus on or study all content
5. **Practice** by answering the prompts and receiving immediate feedback

## Project Structure

- `backEnd/` - Core functionality and logic
  - `alphabet/` - Hiragana and katakana practice module
  - `wordbringer/` - Vocabulary practice module
  - `inflectionmaster/` - Verb and adjective conjugation module
  - `sentencer/` - Sentence translation module
  - `library/` - Vocabulary database management
  - `grammar/` - Japanese and English grammar rules
- `xml/` - Vocabulary and grammar data files
- `resources/` - Images and style resources
- `styles/` - CSS styling for the application

## Future Improvements

- Add audio pronunciation for vocabulary items
- Implement handwriting recognition for character practice
- Expand vocabulary database with more specialized terms
- Add a kanji learning module
- Create user profiles to track individual progress

## License

This project is licensed under the GNU General Public License v2.0 - see the LICENSE file for details.
