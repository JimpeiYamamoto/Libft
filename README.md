# 42_libft

## **概要**  
C言語の標準関数、他の言語で標準としてよく使われる関数、および線形リストを扱う関数のライブラリです。  
関数の名前の頭に`ft_`を付けています。
### 例
```
strlen -> ft_strlen
```
### C言語の標準関数の詳細を確認する場合には以下のコマンドを使用してください。
```
man 名前
```
- ## 標準関数一覧
	### 使用関数`なし`
	- isalpha
	- isdigit
	- isalnum
	- isascii
	- isprint
	- strlen
	- memset
	- bzero
	- memcpy
	- memmove
	- strlcpy
	- strlcat
	- toupper
	- tolower
	- strchr
	- strncmp
	- memchr
	- strnstr
	- atoi
	### 使用関数 `malloc`
	- calloc
	- strdup
- ## 他の関数一覧
	### 使用関数 `なし`
	```
	char *ft_strmapi(char const *s, char (*f)(unsigned int start, size_t len)
	```
	### 使用関数 `malloc`, `free`
	```
	 char *ft_substr(char const *s, unsigned int start, size_t len)
	 ```
	```
	char *ft_strjoin(char const *s1, char const *s2)
	```
	```
	char *ft_strtrim(char const *s1, char const *set)
	```
	```
	char **ft_split(char const *s, char c)
	```
	```
	char *ft_itoa(int n)
	```
	```
	void ft_striteri(char *s, void (*f)(unsigned int, char*))
	```
	### 使用関数 `write`
	```
	void ft_putchar_fd(char c, int fd)
	```
	```
	void ft_putstr_fd(char *s, int fd)
	```
	```
	void ft_putendl_fd(char *s, int fd)
	```
	```
	void ft_putnbr_fd(int n, int fd)
	```
## **コンパイル方法**
```
make
```
```
make bonus*
```
## **使い方**
```
gcc [Your Main] [Other Files] libft.a
```
