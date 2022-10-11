//父类：
public class Person {
 
 
	public String name;
	public int age;
	
	public Person(String name,int age){
	  this.name=name;
	  this.age=age;
	}
	
	public Person() /*如果不写这个构造函数，看看对类Student有什么影响。*/{
		
	}
	
	public void getInfo(){
		System.out.println(name);
		System.out.println(age);
	}	
}
 
//子类：
public class Student extends Person{
	String school;
	public Student(String name,int age,String school){
		super(name,age);
		this.school=school;
	}
	
	public Student(){
		
	}
	
	public void study() {
		 System.out.println("学习非常棒！");
	}
 
public static void main(String[] args)
{
	Person p=new Person();
	p.name="person";
	p.age=45;
	p.getInfo();
	
	Student s=new Student();
	s.name="student";
	s.age=26;
	s.getInfo();
	s.study();	
 }
}
————————————————
版权声明：本文为CSDN博主「jinxueH专栏」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/euxnijuoh/java/article/details/52108863