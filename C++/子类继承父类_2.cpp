/***
子类中可以根据需要对从父类中继承来的方法进行改造----方法的覆盖 （ 也叫重写）。
覆盖方法必须和被覆盖方法具有相同的方法名称、参数列表和返回值类型。


***/

//父类：
package javatest;
 
public class Person {
	public String name;
	public int age;
	
	public Person(String name,int age){
	  this.name=name;
	  this.age=age;
	}
	 //如果不写这个构造函数，看看对类Student有什么影响。
	public Person(){
		
	}
	
	public void getInfo(){
		System.out.println(name);
		System.out.println(age);
	}	
}
 
//子类继承父类：
public class Student extends Person{
	String school;   //父类是没有的，子类特有的
	public Student(String name,int age,String school){
		super(name,age);
		this.school=school;
	}
	
	public Student(){
		
	}
	
	public void study() {
		 System.out.println("学习非常棒！");
	}
 
	public void getInfo()
	{
	 super.getInfo();
	 System.out.println(school);
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
	s.school="清华大学";
	s.getInfo();
	s.study();	
 }
}