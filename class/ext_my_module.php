<?hh

class Hello {
  
  public function greet() {
    echo "Hello {$this->name}\n";
  }

  public function __construct(protected string $name = 'Stranger') {}


  <<__Native>>
  public function getName(): string;

  <<__Native>>
  static public function DefaultHello(): string;
}

