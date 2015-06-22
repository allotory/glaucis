package test;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;
import javax.swing.UIManager;

public class WebCrawler extends JFrame{
	private static final long serialVersionUID = 1L;
	
	//���ڵĿ�Ⱥʹ��ڵĸ߶�
	private int windowWidth = 800;
	private int windowHeight = 600;
	
	//�˵�
	private JMenuBar menuBar = null;
	private JMenu fileMenu = null;
	private JMenuItem savePageItem = null;
	private JMenuItem saveEmailItem = null;
	private JMenuItem exitItem = null;
	private JMenu operateMenu = null;
	private JMenuItem downloadItem = null;
	private JMenuItem crawleItem = null;
	private JMenu helpMenu = null;
	private JMenuItem aboutItem = null;
	
	//���������ļ��Ҳ�Panel
	private JPanel topPanel = null;
	private JPanel centerPanel = null;
	private JPanel rightPanel = null;
	
	//������������ذ�ť����ȡ��ť
	private JLabel urlLabel = null;
	private JTextField urlField = null;
	private JButton downloading = null;
	private JButton crawling = null;
	
	//������ʾ
	private JTextArea pageView = null;
	
	//�Ҳ���ʾ
	private JTextArea emailView = null;
	
	//״̬��
	private JToolBar toolBar = null;
	private JLabel toolBarMsg = null;
	
	public void init() {
		this.setTitle("Web Page Crawler");
		this.setBounds(300, 200, windowWidth, windowHeight);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//���岼��
		this.setLayout(new BorderLayout());
		
		//�˵�
		menuBar = new JMenuBar();
		fileMenu = new JMenu("�ļ�");
		savePageItem = new JMenuItem("������ҳ���ļ�");
		saveEmailItem = new JMenuItem("�����ʼ����ļ�");
		exitItem = new JMenuItem("�˳�");
		operateMenu = new JMenu("����");
		downloadItem = new JMenuItem("����ҳ��");
		crawleItem = new JMenuItem("��ȡ�ʼ���ַ");
		helpMenu = new JMenu("����");
		aboutItem = new JMenuItem("����");
		
		fileMenu.add(savePageItem);
		fileMenu.add(saveEmailItem);
		fileMenu.add(exitItem);
		menuBar.add(fileMenu);
		operateMenu.add(downloadItem);
		operateMenu.add(crawleItem);
		menuBar.add(operateMenu);
		helpMenu.add(aboutItem);
		menuBar.add(helpMenu);
		
		//����Panel
		topPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
		
		urlLabel = new JLabel("��ַ��");
		urlField = new JTextField(100);
		downloading = new JButton("����");
		crawling = new JButton("��ȡ");
		downloading.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
			}
		});
		
		topPanel.add(urlLabel);
		topPanel.add(urlField);
		topPanel.add(downloading);
		topPanel.add(crawling);
		
		//����Panel
		centerPanel = new JPanel();
		//centerPanel.setBackground(Color.black);
		pageView = new JTextArea(24, 85);
		centerPanel.add(BorderLayout.CENTER, pageView);
		
		//�Ҳ�Panel
		rightPanel = new JPanel();
		emailView = new JTextArea(24, 20);
		rightPanel.add(BorderLayout.CENTER, emailView);
		
		//״̬��
		toolBar = new JToolBar();
		toolBarMsg = new JLabel("downloading...");
		toolBar.add(toolBarMsg);
		
		this.setJMenuBar(menuBar);
		this.add(BorderLayout.NORTH, topPanel);
		this.add(BorderLayout.CENTER, centerPanel);
		this.add(BorderLayout.SOUTH, toolBarMsg);
		this.add(BorderLayout.EAST, rightPanel);
		this.setVisible(true);
	}
	
//	public static String download(String url) {
//		new Thread( ()->{
//			String content = getContentFromUrl(url);
//			SwingUtilities.invokeLater(()->{
//				textArea.append( content );
//			});
//		}).start();
//	}

	public static void main(String[] args) {
		String lookAndFeel = UIManager.getSystemLookAndFeelClassName();
		try {
			UIManager.setLookAndFeel(lookAndFeel);
		} catch (Exception e) {
			e.printStackTrace();
		} 
		new WebCrawler().init();
	}

}
