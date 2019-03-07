class Hello{
    public int number;
    public void sayHello(){
        number=20;
        System.out.println("Hello "+20);
    }   
    public static void main(String args[]){
        Hello message = new Hello();
        message.sayHello();

    }

}