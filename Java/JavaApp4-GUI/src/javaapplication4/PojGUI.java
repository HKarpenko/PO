package javaapplication4;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PojGUI extends JFrame{
    private JButton button = new JButton("Zapisz");
    private JLabel LFile = new JLabel("File:");
    private JTextField TFile = new JTextField("",15);
    private JLabel LTyp = new JLabel("Typ:");
    private JTextField TTyp = new JTextField("",15);
    private JLabel LRok = new JLabel("Rok:");
    private JTextField TRok = new JTextField("",15);
    private JLabel LMark = new JLabel("Marka:");
    private JTextField TMark = new JTextField("",15);
    private JLabel LMph = new JLabel("Max szybkosc(samochody):");
    private JTextField TMph = new JTextField("",15);
    private JLabel LOrg = new JLabel("Organizacja (tramwaje):");
    private JTextField TOrg = new JTextField("",15);
    public PojGUI(){
        JFrame.setDefaultLookAndFeelDecorated(true);
        JFrame frame = new JFrame("New Pojazd");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(7,2,2,2));
        panel.add(LTyp);
        panel.add(TTyp);
        panel.add(LRok);
        panel.add(TRok);
        panel.add(LMark);
        panel.add(TMark);
        panel.add(LMph);
        panel.add(TMph);
        panel.add(LOrg);
        panel.add(TOrg);
        panel.add(LFile);
        panel.add(TFile);
        button.addActionListener(new ButListener());
        panel.add(button);
        frame.getContentPane().add(panel);
        frame.setPreferredSize(new Dimension(500, 400));
        frame.pack();
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
    }
    class ButListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            Pojazd poj;
            if(TTyp.getText()=="Tramwaj" || TTyp.getText()=="tramwaj"){
                poj=new Tramwaj(Integer.parseInt(TRok.getText()),TMark.getText(),TOrg.getText());
                poj.Zapisz(TFile.getText());
            }
            else if(TTyp.getText()=="Samochod" || TTyp.getText()=="samochod"){
                poj=new Samochod(Integer.parseInt(TRok.getText()),TMark.getText(),Integer.parseInt(TOrg.getText()));
                poj.Zapisz(TFile.getText());
            }
            else {
                poj=new Pojazd("Unknown Pojazd",Integer.parseInt(TRok.getText()),TMark.getText());
                poj.Zapisz(TFile.getText());
            }
        }
    }
    
    
}
