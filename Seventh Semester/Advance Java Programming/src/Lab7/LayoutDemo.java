package Lab7;

import javax.swing.*;
import java.awt.*;

import java.awt.event.*;

public class LayoutDemo extends JFrame implements ActionListener {
    CardLayout cardLayout = new CardLayout();
    JPanel cardPanel = new JPanel(cardLayout);
    JComboBox<String> layoutCombo;

    public LayoutDemo() {
        setTitle("Swing Layout Managers Demo");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(600, 400);

        // FlowLayout Panel
        JPanel flowPanel = new JPanel(new FlowLayout());
        flowPanel.add(new JButton("One"));
        flowPanel.add(new JButton("Two"));
        flowPanel.add(new JButton("Three"));

        // BorderLayout Panel
        JPanel borderPanel = new JPanel(new BorderLayout());
        borderPanel.add(new JButton("North"), BorderLayout.NORTH);
        borderPanel.add(new JButton("South"), BorderLayout.SOUTH);
        borderPanel.add(new JButton("East"), BorderLayout.EAST);
        borderPanel.add(new JButton("West"), BorderLayout.WEST);
        borderPanel.add(new JButton("Center"), BorderLayout.CENTER);

        // GridLayout Panel
        JPanel gridPanel = new JPanel(new GridLayout(2, 3, 5, 5));
        for (int i = 1; i <= 6; i++)
            gridPanel.add(new JButton("Button " + i));

        // BoxLayout Panel
        JPanel boxPanel = new JPanel();
        boxPanel.setLayout(new BoxLayout(boxPanel, BoxLayout.Y_AXIS));
        boxPanel.add(new JButton("Top"));
        boxPanel.add(Box.createVerticalStrut(10));
        boxPanel.add(new JButton("Middle"));
        boxPanel.add(Box.createVerticalStrut(10));
        boxPanel.add(new JButton("Bottom"));

        // CardLayout Panel (shows only first card)
        JPanel card1 = new JPanel();
        card1.add(new JLabel("This is Card 1"));
        JPanel card2 = new JPanel();
        card2.add(new JLabel("This is Card 2"));
        JPanel card3 = new JPanel();
        card3.add(new JLabel("This is Card 3"));
        JPanel cards = new JPanel(new CardLayout());
        cards.add(card1, "Card1");
        cards.add(card2, "Card2");
        cards.add(card3, "Card3");
        JPanel cardLayoutPanel = new JPanel(new BorderLayout());
        cardLayoutPanel.add(cards, BorderLayout.CENTER);

        // GridBagLayout Panel
        JPanel gridBagPanel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);
        gbc.gridx = 0;
        gbc.gridy = 0;
        gridBagPanel.add(new JButton("A"), gbc);
        gbc.gridx = 1;
        gridBagPanel.add(new JButton("B"), gbc);
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 2;
        gridBagPanel.add(new JButton("Wide Button"), gbc);

        // Add all layout panels to CardLayout panel
        cardPanel.add(flowPanel, "FlowLayout");
        cardPanel.add(borderPanel, "BorderLayout");
        cardPanel.add(gridPanel, "GridLayout");
        cardPanel.add(boxPanel, "BoxLayout");
        cardPanel.add(cardLayoutPanel, "CardLayout");
        cardPanel.add(gridBagPanel, "GridBagLayout");

        // ComboBox to select layout
        String[] layouts = { "FlowLayout", "BorderLayout", "GridLayout", "BoxLayout", "CardLayout", "GridBagLayout" };
        layoutCombo = new JComboBox<>(layouts);
        layoutCombo.addActionListener(this);

        // Main frame layout
        setLayout(new BorderLayout());
        add(layoutCombo, BorderLayout.NORTH);
        add(cardPanel, BorderLayout.CENTER);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == layoutCombo) {
            String selected = (String) layoutCombo.getSelectedItem();
            cardLayout.show(cardPanel, selected);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new LayoutDemo().setVisible(true));
    }
}