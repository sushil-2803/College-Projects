
    import javax.swing.*;
    import java.awt.event.*;
    import java.awt.*;
    import java.io.File;
    import javax.swing.filechooser.FileNameExtensionFilter;
    import java.util.*;

     class LoginFrame extends JFrame
     {
         JButton b1 , b2;
         JLabel l1;
    
         public LoginFrame()
         {
             super("LOGIN PAGE");
             setSize(800 , 550);
             setResizable(true);
             setLocation(200 , 50); 
             setLayout(null);
             setDefaultCloseOperation(EXIT_ON_CLOSE);
               
             b1 = new JButton(" WELCOME TO MY PROJECT ");
             b1.setBounds(250, 400 , 300 , 50);
             add(b1);                            

             l1 = new JLabel();
             l1.setBounds(200, 30 , 700 , 300);    
             l1.setIcon(new ImageIcon("9.jpg"));  
             add(l1);            

             b1.addActionListener( new ActionListener()
             {
                   public void actionPerformed(ActionEvent e)
                   {      
                              LoginFrame.this.setVisible(false);
                                  new Frame2();            
                   }
             });
 
              setVisible(true); 
         }
   }


   class Frame2 extends JFrame
   {
         JLabel l1,l2,l3,l4,l5,l6,l7;
         JTextField t1,t2,t3,t4,t5;
         ButtonGroup bg1;
         JRadioButton rb1 , rb2;
         JButton b1, b2, b3;
         String data;

         public Frame2()
         {
             super("STUDENT DETAILS");
             setSize(500 , 500);
             setResizable(true);
             setLocation(200 , 50); 
             setLayout(null);
             setDefaultCloseOperation(EXIT_ON_CLOSE);

              l1 = new JLabel("ENTER FIRST NAME ");
              l1.setBounds(80 , 50 , 150 , 30);
              add(l1); 

              t1 = new JTextField();
              t1.setBounds(230 , 50 , 200 , 30);
              add(t1); 

              l2 = new JLabel("ENTER LAST NAME ");
              l2.setBounds(80 , 100 , 150 , 30);
              add(l2); 

              t2 = new JTextField();
              t2.setBounds(230 , 100 , 200 , 30);
              add(t2); 

             rb1 = new JRadioButton("MALE");
             rb2 = new JRadioButton("FEMALE");

             bg1 = new ButtonGroup();
             bg1.add(rb1);
             bg1.add(rb2); 
              
             l3 = new JLabel("SELECT GENDER ");
             l3.setBounds(80,150,150,30);
             add(l3);

             rb1.setBounds(230 , 150 , 80 , 30);
             rb2.setBounds(330 , 150 , 80 , 30); 

             add(rb1);
             add(rb2);

              l4 = new JLabel(" ENTER BRANCH ");
              l4.setBounds(80 , 190 , 150 , 30);
              add(l4); 

              t3 = new JTextField();
              t3.setBounds(230 , 190 , 200 , 30);
              add(t3); 

              l5 = new JLabel("ENTER ADDRESS ");
              l5.setBounds(80 , 230 , 150 , 30);
              add(l5); 

              t4 = new JTextField();
              t4.setBounds(230 , 230 , 200 , 30);
              add(t4); 

              b2 = new JButton("SUBMIT DETAILS");
              b2.setBounds(150 , 330 , 150, 30);
              add(b2);
                
       b2.addActionListener(new ActionListener()
       {
             public void actionPerformed(ActionEvent ae)
             {
                     if(t1.getText().equals(""))   
                     {
       			 JOptionPane.showMessageDialog(Frame2.this,"Please Enter FIRST NAME","ALERT",JOptionPane.PLAIN_MESSAGE); 
                             return;
                     }
		     else if(t2.getText().equals(""))
		     {
			JOptionPane.showMessageDialog(Frame2.this,"Please Enter LAST NAME","ALERT",JOptionPane.PLAIN_MESSAGE);
		     }
		     else if(t3.getText().equals(""))
		     {
			JOptionPane.showMessageDialog(Frame2.this,"Please Enter DEPARTMENT","ALERT",JOptionPane.PLAIN_MESSAGE);
		     }
		     else if(t4.getText().equals(""))
 		     {
			JOptionPane.showMessageDialog(Frame2.this,"Please Enter ADDRESS","ALERT",JOptionPane.PLAIN_MESSAGE);
		     }
                     else
                     {   
        		String s1 = "STUDENT NAME : "+t1.getText().trim()+" "+t2.getText().trim()+"\n";
             		String s2 = "ADDRESS : "+t4.getText().trim();
            	 	String s3 = "BRANCH : "+t3.getText().trim();
           
                          Frame2.this.setVisible(false);
                          new Frame3(s1 , s2 , s3);                      
                     }
             }
       });  
                setVisible(true);
         } 
   }

   class Frame3 extends JFrame 
   {
          JLabel l1 , l2, l3, l4, l5;
	  JButton b1, b2;

         public Frame3(String s1, String s2, String s3)
         {
             super("STUDENT");
             setSize(1000 , 900);
             setResizable(true);
             setLocation(200 , 70); 
             setLayout(null);
             setDefaultCloseOperation(EXIT_ON_CLOSE);

            l1 = new JLabel(s1);
            l1.setBounds(50 , 20 , 300 , 30);
             add(l1);

            l2 = new JLabel(s2);
            l2.setBounds(50 , 70 , 300 , 30);
             add(l2);

            l3 = new JLabel(s3);
            l3.setBounds(50 , 120 , 300 , 30);
            add(l3);	    
	    
	    b1 = new JButton(" MAKE A NEW ENTERY ");
            b1.setBounds(250, 400 , 150 , 50);
            add(b1);

            b2 = new JButton(" EXIT ");
            b2.setBounds(350, 400 , 150 , 50);
            add(b2);
            
            b1.addActionListener( new ActionListener()
             {
                   public void actionPerformed(ActionEvent e)
                   {      
                              setVisible(false);
                               new Frame2();            
                   }
             });
            b2.addActionListener( new ActionListener()
             {
                   public void actionPerformed(ActionEvent e)
                   {      
                              System.exit(0);
                   }
             });

                     setVisible(true); 
         }
   }
     
   public class JavaProject
   {
       public static void main(String [] args)
       {
              new LoginFrame();
       }
   }  

