# 42_libft

## 概要  
- C言語の標準関数
- 他の言語でよく使用される標準関数
- 線形リストを扱う関数  

自作と標準関数を区別するために関数の名前の頭に`ft_`を付けています。
### 例
```
strlen -> ft_strlen
```
### C言語の標準関数の参照
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
	```c
	char *ft_strmapi(char const *s, char (*f)(unsigned int start, size_t len)
	```
	### 使用関数 `malloc`, `free`
	```c
	 char *ft_substr(char const *s, unsigned int start, size_t len)
	```
	```c
	char *ft_strjoin(char const *s1, char const *s2)
	```
	```c
	char *ft_strtrim(char const *s1, char const *set)
	```
	```c
	char **ft_split(char const *s, char c)
	```
	```c
	char *ft_itoa(int n)
	```
	```c
	void ft_striteri(char *s, void (*f)(unsigned int, char*))
	```
	### 使用関数 `write`
	```c
	void ft_putchar_fd(char c, int fd)
	```
	```c
	void ft_putstr_fd(char *s, int fd)
	```
	```c
	void ft_putendl_fd(char *s, int fd)
	```
	```c
	void ft_putnbr_fd(int n, int fd)
	```

- ## 線形リスト用の関数一覧
	### 線形リストの構造体
	```c
	typedef struct s_list
	{
		void *content;
		struct s_list *next;
	} t_list;
	```
	### 使用関数 `malloc` `free`
	```c
	t_list *ft_lstnew(void *content);
	```
	```c
	void ft_lstadd_front(t_list **lst, t_list *new)
	```
	```c
	int ft_lstsize(t_list *lst)
	```
	```c
	t_list *ft_lstlast(t_list *lst)
	```
	```c
	void ft_lstadd_back(t_list **lst, t_list *new)
	```
	```c
	void ft_lstdelone(t_list *lst, void (*del)(void*))
	```
	```c
	void ft_lstclear(t_list **lst, void (*del)(void*))
	```
	```c
	void ft_lstiter(t_list *lst, void (*f)(void *))
	```
	```c
	t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
	```
## 使用方法
### ①インストール
```
git clone git@github.com:JimpeiYamamoto/42_libft.git libft
```
```
cd libft
```
### ②コンパイル
- #### 線形リストなしライブラリ
	```
	make
	```
- #### 線形リストありライブラリ
	```
	make bonus
	```
	`libft.a` ファイルが生成されます。
### ③ライブラリとヘッダーファイルをコピー  
`path` に使用したいフォルダを指定
```
cp libft.a [path]
cp libft.h [path]
```
### ④include
使用する`.c`ファイルの上部、又はヘッダーファイルに以下を記載
```c
#include "libft.h"
```
### ⑤コンパイル
```
gcc [Your Main] [Other Files] libft.a
```
#### ぜひ使ってください :)