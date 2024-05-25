import java.awt.*;
import java.awt.event.*;
class awt8 extends Frame
{
private Button b1,b2;
private Checkbox cb1,cb2;
private TextArea ta;
awt8()
{
b1=new Button("Send");
b2=new Button("Unsend");
cb1=new Checkbox("Football");
cb2=new Checkbox("Above 18");
ta=new TextArea();
setLayout(new FlowLayout());
cb1.addItemListener(new ItemListener()
{
public void itemStateChanged(ItemEvent ie)
{
System.out.println("Football state :"+cb1.getState());
updateStates();
}
});
cb2.addItemListener(new ItemListener()
{
public void itemStateChanged(ItemEvent ie)
{
System.out.println("Above 18 :"+cb2.getState());
updateStates();
}
});
addWindowListener(new WindowAdapter(){
public void windowClosing(WindowEvent we)
{
System.exit(0);
}
});
BorderLayout bl=new BorderLayout();

add(cb1);
add(cb2);
add(ta);
setLocation(500,210);
setSize(500,400);
setVisible(true);
}
public void updateStates()
{
ta.setText("");
if(cb1.getState()) ta.append("Football state :checked\n");
else ta.append("Football state :unchecked\n");
 
if(cb2.getState()) ta.append("Above 18 state:checked\n");
else ta.append("Above 18 state:unchecked\n");
}
}
class awt8psp
{
public static void main(String gg[])
{
awt8 a=new awt8();
}
}