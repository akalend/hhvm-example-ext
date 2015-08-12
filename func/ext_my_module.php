<?hh
function hello_word() {
  echo "Hello World\n";
}

<<__Native>>
function hello_goodbye(string $name, bool $hello = true): String;

<<__Native>>
function get_data(string $data): Array;
