<p align="center"><img src="../../.github/libftbanner.png" alt="Profile banner"/></p>

<p align="justify">The <code>libft</code> project is the first one I developed as a 42 student. Which consisted on creating my very first C library from scratch.<br><br>This version of the project also include more advanced projects like <code>ft_printf</code> and <code>get_next_line</code>, since now they are part of the original <code>libft</code>. The version that you are now seeing of the <code>libft</code> is the complete one.</p>

- **Reminder:** ❗️ You can check all my 42 projects at <a href="https://github.com/jandrana/42-Cursus">42 Cursus</a>

## Table of Contents

<table>
    <thead>
        <tr>
            <th colspan="4" id="original-functions" margin="30"><h3>Makefile and Header File</h3></th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td colspan="1"><a href="./functions"><code>functions</code></a></td>
            <td colspan="3">Here you can fing the original functions of the first final version of the <code>libft</code> project.</td>
        </tr>
        <tr>
            <td width="10%"><a href="./ft_printf"><code>ft_printf</code></a></td>
            <td width="40%">This folder contains the <code>ft_printf</code> functions.</td>
            <td width="10%"><a href="./get_next_line"><code>get_next_line</code></a></td>
            <td width="40%">This folder contains the <code>get_next_line</code> functions.</td>
        </tr>
    </tbody>
</table>


## Usage

### Supported Platforms

- **Linux**
- **macOS**

### Prerequisites

Before using Libft, you need:

- **GCC**: The GNU Compiler Collection.

### Compilation

Make use of the `make` command to build and compile the library

Rules Available in the Makefile

<table>
    <thead>
        <th>Rule</th>
        <th>Description</th>
    </thead>
    <tbody>
        <tr>
            <td>all</td>
            <td>Compiles the library without the bonus files</td>
        </tr>
        <tr>
            <td>bonus</td>
            <td>Compiles the library with bonus files</td>
        </tr>
        <tr>
            <td>clean</td>
            <td>Removes every created object</td>
        </tr>
        <tr>
            <td>fclean</td>
            <td>Runs <code>make clean</code> and removes the libft.a</td>
        </tr>
        <tr>
            <td>re</td>
            <td>Runs <code>make fclean</code> and then <code>make all</code></td>
        </tr>
        <tr>
            <td>rebonus</td>
            <td>Runs <code>make fclean</code> and then <code>make bonus</code></td>
        </tr>
    </tbody>
</table>

### Compilation Examples

- Compile without bonus:
```bash
cd libft
make all
```

- Delete objects and libft.a and compile with bonus:
```bash
make rebonus

```
